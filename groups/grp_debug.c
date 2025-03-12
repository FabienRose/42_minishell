/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:59:27 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/12 16:33:03 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static void grp_debug_printbefore(t_grp *grp, char *tabs, int tab_count)
{
	t_cmd *cmd;
	t_grp *sgrp;
	if(grp->bcall_type == GRP_COMMAND && grp->bcall)
	{
		cmd = (t_cmd *)(grp->bcall);
		printf("%i %s Before call (COMMAND): %p --> %s\n", tab_count, tabs, cmd, cmd->name);
	}
	else if(grp->bcall_type == GRP_GROUP && grp->bcall)
	{
		sgrp = (t_grp *)(grp->bcall);
		printf("%i %s Before call (GROUP): %p\n", tab_count, tabs, sgrp);
	}
	else
	{
		printf("%i %s Before call (NONE)\n", tab_count, tabs);
	}
}
static void grp_debug_printafter(t_grp *grp, char *tabs, int tab_count)
{
	t_cmd *cmd;
	t_grp *sgrp;
	if(grp->acall_type == GRP_COMMAND && grp->acall)
	{
		cmd = (t_cmd *)(grp->acall);
		printf("%i %s After call (COMMAND): %p --> %s\n", tab_count, tabs, cmd, cmd->name);
	}
	else if(grp->acall_type == GRP_GROUP && grp->acall)
	{
		sgrp = (t_grp *)(grp->acall);
		printf("%i %s After call (GROUP): %p\n", tab_count, tabs, sgrp);
	}
	else
	{
		printf("%i %s After call (NONE)\n", tab_count, tabs);
	}
}

void grp_debug(t_grp *grp, int tab_count)
{
	char *tabs;
	size_t pos;

	tabs = ft_calloc(sizeof(char), tab_count * 4 + 1);
	if(!tabs)
		return;
	ft_memset(tabs, '*', tab_count * 4);
	printf("%i %s GRP: %p\n", tab_count, tabs, grp);
	printf("%i %s Tokens: ↓\n", tab_count, tabs);
	pos = 0;
	while(pos < ft_arraylen_d((void **)(grp->tokens)))
	{
		printf("%i %s   %s: %p (%i)\n", tab_count, tabs, grp->tokens[pos]->input, grp->tokens[pos], grp->tokens[pos]->lastid);
		pos++;
	}
	grp_debug_printbefore(grp, tabs, tab_count);
	grp_debug_printafter(grp, tabs, tab_count);
	printf("%i %s SUBs: ↓\n\n", tab_count, tabs);
	pos = 0;
	while(pos < ft_arraylen_d((void **)(grp->sub_grps)))
	{
		grp_debug(grp->sub_grps[pos], tab_count + 1);
		pos++;
	}
	free(tabs);
}
