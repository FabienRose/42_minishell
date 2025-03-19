/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:21:01 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 18:31:38 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_promptret grp_getio_applytoken_end(t_grp *grp, t_token *token)
{
	if(ft_strlen(grp->reader->buffer) == 0)
	{
		token->type = 0;
		tok_checkvalidity(token);
		return (PMT_FAILED);
	}
	return (grp_getio_applytoio(grp, token));
}

static t_promptret grp_getio_applytoken(t_grp *grp, t_token *token, size_t *pos)
{
	t_bool		found;
	t_promptret	status;

	found = FALSE;
	while(grp->input[*pos])
	{
		if(grp_canapply(grp->reader) 
			&& (ft_isspace(grp->input[*pos]) || tok_iscontrole(grp->input[*pos])) 
			&& found)
			break;
		else if(grp_canapply(grp->reader) 
		&& (ft_isspace(grp->input[*pos]) || tok_iscontrole(grp->input[*pos])))
			(void)found;
		else
		{
			status = grp_read_addchar(grp->reader, grp->input[*pos], TRUE);
			if(status != PMT_SUCCESS)
				return (status);
			found = TRUE;
		}
		(*pos)++;
	}
	return (grp_getio_applytoken_end(grp, token));
}

static t_promptret grp_getio_ontoken_ret(t_token **token, t_promptret status)
{
	tok_clear(token);
	return status;
}

static t_promptret grp_getio_ontoken(t_grp *grp, size_t *pos)
{
	t_token* ntoken;
	size_t start_pos;
	t_promptret status;

	start_pos = *pos;
	ntoken = tok_create(grp->l_shell);
	if(!ntoken || !tok_parse(ntoken, grp, pos))
		return (grp_getio_ontoken_ret(&ntoken, PMT_ERROR));
	if(!tok_checkvalidity(ntoken))
		return (grp_getio_ontoken_ret(&ntoken, PMT_FAILED));
	if(!tok_is_redir(ntoken))
	{
		tok_clear(&ntoken);
		*pos = start_pos;
		return (grp_read_addchar(grp->reader, grp->input[*pos], FALSE));
	}
	if(!grp_getio_merge(grp))
	{
		tok_clear(&ntoken);
		return (PMT_ERROR);
	}
	status = grp_getio_applytoken(grp, ntoken, pos);
	tok_clear(&ntoken);
	(*pos)--;
	return (status);
}

t_promptret grp_getio(t_grp *grp)
{
	size_t pos;
	t_promptret status;
	
	grp_read_reset(grp->reader);
	grp->input_after_io = ft_calloc(sizeof(char), 1);
	if(!grp->input_after_io)
		return (PMT_ERROR);
	pos = 0;
	while(grp->input[pos])
	{
		if(tok_isio(grp->input[pos]) && grp_canapply(grp->reader))
			status = grp_getio_ontoken(grp, &pos);
		else
			status = grp_read_addchar(grp->reader, grp->input[pos], FALSE);
		if(status != PMT_SUCCESS)
			return (status);
		pos++;
	}
	if(!grp_getio_merge(grp))
		return (PMT_ERROR);
	return (PMT_SUCCESS);
}
