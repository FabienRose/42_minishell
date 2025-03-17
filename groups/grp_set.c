/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:51:12 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/17 17:40:50 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret grp_set_subgroups(t_grp *grp)
{
	t_promptret status;
	
	if(!grp->input_before || !grp->input_after)
		return (PMT_FAILED);
	grp->grp_before = grp_create(grp->l_shell);
	if(!grp->grp_before)
		return (PMT_ERROR);
	status = grp_set_input(grp->grp_before, grp->input_before);
	if(status != PMT_SUCCESS)
		return (status);
	grp->grp_after = grp_create(grp->l_shell);
	if(!grp->grp_after)
		return (PMT_ERROR);
	status = grp_set_input(grp->grp_after, grp->input_after);
	return (status);
}
static t_promptret grp_set_subcheck(t_grp *grp)
{
	t_promptret status;
	
	if(!grp->token)
	{
		status = grp_set_split(grp, '|', TOK_OR);
		if(status != PMT_SUCCESS)
			return status;
	}
	if(!grp->token)
	{
		status = grp_set_split(grp, '|', TOK_PIPE);
		if(status != PMT_SUCCESS)
			return status;
	}
	return (PMT_SUCCESS);
}

t_promptret grp_set_input(t_grp *grp, const char *input)
{
	t_promptret status;
	
	grp->input = ft_strdup(input);
	if(!grp->input)
		return (PMT_FAILED);
	status = grp_set_split(grp, '&', TOK_AND);
	if(status != PMT_SUCCESS)
		return status;
	status = grp_set_subcheck(grp);
	if(status != PMT_SUCCESS)
		return status;
	if(grp->token)
		status = grp_set_subgroups(grp);
	else
	{
		status = grp_check_uniq(grp);
	}
	return (status);
}
