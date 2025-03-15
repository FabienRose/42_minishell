/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:51:12 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 13:08:21 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_promptret grp_set_split_ontoken(t_grp *grp, char token, t_token_type target_type, size_t *pos)
{
	t_token* ntoken;
	char *error_msg;
	size_t start_pos;

	start_pos = *pos;
	ntoken = tok_create(grp->l_shell);
	if(!ntoken)
		return (PMT_ERROR);
	if(!tok_parse(ntoken, grp, pos))
		return (PMT_ERROR);
	if(!tok_checkvalidity(ntoken))
		return (PMT_FAILED);
	if(ntoken->type != target_type)
	{
		tok_clear(&ntoken);
		*pos = start_pos;
		return (PMT_SUCCESS);
	}
	grp->token = ntoken;
	return (PMT_SUCCESS);
}

static t_promptret grp_set_split(t_grp *grp, char token, t_token_type target_type)
{
	size_t pos;
	t_promptret status;

	pos = 0;
	while(grp->input[pos])
	{
		if(grp->input[pos] == token && grp_canapply(grp->reader))
		{
			status = grp_set_split_ontoken(grp, token, target_type, &pos);
			if(status != PMT_SUCCESS)
				return (status);
		}
		else
		{
			status = grp_read_addchar(grp->reader, grp->input[pos]);
			if(status != PMT_SUCCESS)
				return (status);
		}
	}
	return (PMT_SUCCESS);
}

t_promptret grp_set_input(t_grp *grp, const char *input)
{
	grp->input = ft_strdup(input);
	if(!grp->input)
		return (PMT_FAILED);
	return (PMT_SUCCESS);
}