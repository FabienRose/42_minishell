/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:14:20 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 14:49:19 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret	grp_check_double(t_grp *grp)
{
	if (grp->is_uniq
		&& grp->input_uniq
		&& !grp->io)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(grp->input_uniq, 2);
		ft_putstr_fd(": syntax error in expression\n", 2);
		return (PMT_FAILED);
	}
	return (PMT_SUCCESS);
}
