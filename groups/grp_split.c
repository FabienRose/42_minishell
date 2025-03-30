/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:47:37 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/30 12:08:16 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_promptret grp_set_split_extract(t_grp* grp)
{
	if(!grp->input_before)
	{
		grp->input_before = grp_read_extract(grp->reader);
		if(!grp->input_before)
			return (PMT_ERROR);
	}
	else if(!grp->input_after)
	{
		grp->input_after = grp_read_extract(grp->reader);
		if(!grp->input_after)
			return (PMT_ERROR);
	}
	return (PMT_SUCCESS);
}

static t_promptret grp_set_split_ontoken(t_grp *grp, t_token_type target_type, size_t *pos)
{
	t_token* ntoken;
	size_t start_pos;

	start_pos = *pos;
	ntoken = tok_create(grp->l_shell);
	if(!ntoken)
		return (PMT_ERROR);
	if(!tok_parse(ntoken, grp->input, pos))
	{
		tok_clear(&ntoken);
		return (PMT_ERROR);
	}
	if(!tok_checkvalidity(ntoken))
	{
		tok_clear(&ntoken);
		return (PMT_FAILED);
	}
	if(ntoken->type != target_type)
	{
		tok_clear(&ntoken);
		*pos = start_pos;
		return (grp_read_addchar(grp->reader, grp->input[*pos], FALSE));
	}
	grp->token = ntoken;
	return (grp_set_split_extract(grp));
}

t_promptret grp_set_split(t_grp *grp, char token, t_token_type target_type)
{
	size_t pos;
	t_promptret status;

	pos = 0;
	grp_read_reset(grp->reader);
	while(grp->input[pos])
	{
		if(grp->input[pos] == token && grp_canapply(grp->reader) && !grp->token)
		{
			status = grp_set_split_ontoken(grp, target_type, &pos);
			if(status != PMT_SUCCESS)
				return (status);
		}
		else
		{
			status = grp_read_addchar(grp->reader, grp->input[pos], FALSE);
			if(status != PMT_SUCCESS)
				return (status);
		}
		pos++;
	}
	if(grp->token)
		return(grp_set_split_extract(grp));
	return (PMT_SUCCESS);
}
