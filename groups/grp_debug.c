/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:44:47 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 11:48:15 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

void grp_debug(t_grp *grp, int tab_count)
{
	char *tabs;

	tabs = ft_calloc(sizeof(char), tab_count * 4 + 1);
	if(!tabs)
		return;
	ft_memset(tabs, '*', tab_count * 4);
	printf("%i %s GRP: %p\n", tab_count, tabs, grp);
	printf("%i %s Input: %s\n", tab_count, tabs, grp->input);
	free(tabs);
}