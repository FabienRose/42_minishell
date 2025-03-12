/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_regroup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:09:14 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/12 17:19:46 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_bool grp_regroup_split(t_grp* grp, size_t start_pos, size_t end_pos)
{
	t_grp *ngrp;
	
	if(start_pos == end_pos)
		return  (TRUE);
	if(start_pos > end_pos)
		return (FALSE);
	ngrp = grp_create();
	if(!ngrp)
		return (FALSE);
	if(!ft_arraypush_d((void***)&(grp->sub_grps), ngrp))
	{
		grp_clear(&ngrp);
		return (FALSE);
	}
	while(start_pos != end_pos && end_pos > 0)
	{
		if(!ft_arraypush_d((void ***)&(ngrp->tokens), grp->tokens[start_pos]))
			return (FALSE);
		if(!ft_arraypopat_d((void ***)&(grp->tokens), start_pos))
			return (FALSE);
		end_pos--;
	}
	return (grp_regroup(ngrp, 0));
}

static t_bool grp_regroup_presplit(t_grp* grp, size_t *pos)
{
	if(!grp_regroup_split(grp, 0, *pos))
		return (FALSE);
	if(!grp_regroup_split(grp, 1, ft_arraylen_d((void **)(grp->tokens))))
		return (FALSE);
	(*pos)--;
	return (TRUE);
}

t_bool grp_regroup(t_grp* grp, int pass)
{
	size_t pos;

	pos = 0;
	while(grp->tokens[pos] && ft_arraylen_d((void **)(grp->tokens)) > 1)
	{
		if(pass == 0 && grp->tokens[pos]->type == TOK_AND)
		{
			if(!grp_regroup_presplit(grp, &pos))
				return (FALSE);
		}
		else if(pass > 0 && grp->tokens[pos]->type == TOK_OR)
		{
			if(!grp_regroup_presplit(grp, &pos))
				return (FALSE);
		}
		pos++;
	}
	if(pass == 0)
		return (grp_regroup(grp, 1));
	return (TRUE);
}
