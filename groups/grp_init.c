/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:07:05 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 10:46:58 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
void *grp_new()
{
	return grp_create();	
}
t_grp *grp_create()
{
	t_grp *ngrp;
	ngrp = ft_calloc(sizeof(t_grp), 1);
	if(!ngrp)
		return (NULL);
	if(!grp_init(ngrp))
	{
		grp_clear(&ngrp);
		return (NULL);
	}
	return (ngrp);
}
t_bool grp_init(t_grp *grp)
{
	grp->reader = grp_read_create();
	if(!grp->reader)
		return (FALSE);
	grp->input = NULL;
	return (TRUE);
}