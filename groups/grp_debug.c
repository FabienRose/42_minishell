/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:44:47 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 15:05:19 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static void grp_debug_sub(t_grp  *grp, char *tabs, int tab_count)
{
	if(grp->grp_before)
	{
		printf("\n%i %s ==BEFORE GROUPE==\n", tab_count, tabs);
		grp_debug(grp->grp_before, tab_count + 1);
	}
	if(grp->grp_after)
	{
		printf("\n%i %s ==AFTER GROUPE==\n", tab_count, tabs);
		grp_debug(grp->grp_after, tab_count + 1);
	}
	if(grp->grp_uniq)
	{
		printf("\n%i %s ==UNIQ GROUPE==\n", tab_count, tabs);
		grp_debug(grp->grp_uniq, tab_count + 1);
	}
}
void grp_debug(t_grp *grp, int tab_count)
{
	char *tabs;

	tabs = ft_calloc(sizeof(char), tab_count * 4 + 1);
	if(!tabs)
		return;
	ft_memset(tabs, '*', tab_count * 4);
	printf("%i %s GRP: %p\n", tab_count, tabs, grp);
	printf("%i %s Input: %s\n", tab_count, tabs, grp->input);
	printf("%i %s Input before: %s\n", tab_count, tabs, grp->input_before);
	printf("%i %s Input after: %s\n", tab_count, tabs, grp->input_after);
	printf("%i %s Input uniq: %s\n", tab_count, tabs, grp->input_uniq);
	if(grp->token)
	{
		printf("%i %s ==TOKEN==\n", tab_count, tabs);
		tok_print(grp->token, tabs, tab_count);
	}
	if(grp->cmd)
	{
		printf("%i %s ==COMMAND==\n", tab_count, tabs);
		cmd_print(grp->cmd, tabs, tab_count);
	}
	grp_debug_sub(grp, tabs, tab_count);
	free(tabs);
}
