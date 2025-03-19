/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:07:05 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 14:13:00 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
t_grp *grp_create(void *shell)
{
	t_grp *ngrp;
	ngrp = ft_calloc(sizeof(t_grp), 1);
	if(!ngrp)
		return (NULL);
	if(!grp_init(ngrp, shell))
	{
		grp_clear(&ngrp);
		return (NULL);
	}
	return (ngrp);
}
t_bool grp_init(t_grp *grp, void *shell)
{
	grp->reader = grp_read_create(shell);
	if(!grp->reader)
		return (FALSE);
	grp->input = NULL;
	grp->input_before = NULL;
	grp->input_after = NULL;
	grp->input_uniq = NULL;
	grp->token = NULL;
	grp->grp_before = NULL;
	grp->grp_after = NULL;
	grp->grp_uniq = NULL;
	grp->cmd = NULL;
	grp->l_shell = shell;
	return (TRUE);
}