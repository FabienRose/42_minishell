/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:14:43 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/11 17:14:50 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

void grp_release(void *grp)
{
	grp_clear((t_grp **)&grp);
}
void grp_clear(t_grp **grp)
{
	if(!grp || !(*grp))
		return ;
	t_grp *c_grp = *grp;
	ft_arrayfree_d((void ***)&(c_grp->sub_grps), &grp_release);
	ft_arrayfree((void**)&(c_grp->tokens));
	free(c_grp);
	*grp = NULL;
}