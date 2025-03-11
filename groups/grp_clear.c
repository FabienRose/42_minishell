/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:14:43 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/09 14:34:58 by kgauthie         ###   ########.fr       */
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
	ft_arrayfree((void **)&(c_grp->input_files));
	ft_arrayfree((void **)&(c_grp->output_files));
	ft_arrayfree((void **)&(c_grp->output_endfiles));
	ft_arrayfree((void **)&(c_grp->input_stdin));
	free(c_grp);
	*grp = NULL;
}