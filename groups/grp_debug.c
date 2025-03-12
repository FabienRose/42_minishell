/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:59:27 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/11 17:57:42 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

void grp_debug(t_grp *grp, int tab_count)
{
	char *tabs;
	size_t pos;

	tabs = ft_calloc(sizeof(char), tab_count + 1);
	if(!tabs)
		return;
	ft_memset(tabs, '\t', tab_count);
	printf("%s---- GRP: %p ----\n\n", tabs, grp);
	printf("%s--Tokens: ↓--\n\n", tabs);
	pos = 0;
	while(pos < ft_arraylen_d((void **)(grp->tokens)))
	{
		printf("%s%s: %p\n", tabs, grp->tokens[pos]->input, grp->tokens[pos]);
		pos++;
	}
	printf("\n%s--SUBs: ↓--\n\n", tabs);
	pos = 0;
	while(pos < ft_arraylen_d((void **)(grp->sub_grps)))
	{
		grp_debug(grp->sub_grps[pos], tab_count + 1);
		pos++;
	}
	free(tabs);
}
