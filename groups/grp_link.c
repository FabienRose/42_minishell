/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:49:26 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/12 17:07:16 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

void grp_link(t_grp* grp, int placement, t_grp_type type, void *target)
{
	if(placement == -1)
	{
		grp->bcall_type = type;
		grp->bcall = target;
	}
	else if(placement == 1)
	{
		grp->acall_type = type;
		grp->acall = target;
	}
}