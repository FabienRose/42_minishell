/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:51:12 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/30 14:46:11 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret grp_set_subgroups(t_grp *grp)
{
	t_promptret status;
	
	if(!grp->input_before 
		|| !grp->input_after
		|| ft_isonlyspace(grp->input_before)
		|| ft_isonlyspace(grp->input_after))
	{
		tok_unvalid(grp->token, grp->is_uniq);
		return (PMT_FAILED);
	}
	grp->grp_before = grp_create(grp->l_shell);
	if(!grp->grp_before)
		return (PMT_ERROR);
	status = grp_set_input(grp->grp_before, grp->input_before, FALSE);
	if(status != PMT_SUCCESS)
		return (status);
	grp->grp_after = grp_create(grp->l_shell);
	if(!grp->grp_after)
		return (PMT_ERROR);
	status = grp_set_input(grp->grp_after, grp->input_after, FALSE);
	return (status);
}
static t_promptret grp_set_subcheck(t_grp *grp)
{
	t_promptret status;
	
	status = grp_set_split(grp, '&', TOK_AND);
	if(status != PMT_SUCCESS)
		return status;
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

static t_promptret grp_set_input_sub(t_grp *grp)
{
	t_promptret status;
	
	status = grp_check_uniq(grp);
	if(status != PMT_SUCCESS)
		return (status);
	status = grp_getio(grp);
	if(status != PMT_SUCCESS)
		return (status);
	if(!grp->grp_uniq)
		status = grp_getcmd(grp);
	else
		status = grp_check_residue(grp);
	if(status != PMT_SUCCESS)
		return (status);
	return (status);
}

t_promptret grp_set_input(t_grp *grp, const char *input, t_bool is_first)
{
	t_promptret status;
	
	status = grp_parseinput(grp, input, is_first);
	if(status != PMT_SUCCESS)
		return status;
	status = grp_set_subcheck(grp);
	if(status != PMT_SUCCESS)
		return status;
	if(grp->token)
		status = grp_set_subgroups(grp);
	else
	{
		status = grp_set_input_sub(grp);
		if(status != PMT_SUCCESS)
			return (status);
	}
	return (status);
}
