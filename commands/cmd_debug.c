/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:10:54 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 15:20:05 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void cmd_print(t_cmd* cmd, char *tabs, int tab_count)
{
	size_t pos;
	
	printf("%i %s    Input: %s\n", tab_count, tabs, cmd->name);
	printf("%i %s    Args: %li\n", tab_count, tabs, ft_arraylen_d((void **)(cmd->args)));
	pos = 0;
	while(cmd->args[pos])
	{
		printf("%i %s       %li: %s\n", tab_count, tabs, pos, cmd->args[pos]);
		pos++;
	}
	printf("%i %s    Full: %li\n", tab_count, tabs, ft_arraylen_d((void **)(cmd->full)));
	pos = 0;
	while(cmd->full[pos])
	{
		printf("%i %s       %li: %s\n", tab_count, tabs, pos, cmd->full[pos]);
		pos++;
	}
}