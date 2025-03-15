/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:51:12 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 10:56:03 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret grp_set_input(t_grp *grp, const char *input)
{
	grp->input = ft_strdup(input);
	if(!grp->input)
		return (PMT_FAILED);
	return (PMT_SUCCESS);
}