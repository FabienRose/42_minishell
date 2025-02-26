/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:10:22 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 08:14:17 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void cmd_print(t_cmd* cmd)
{
	size_t i;
	
	if(!cmd)
	{
		printf("Debug: no cmd passed");
		return ;
	}
	if(cmd->name)
		printf ("Name: %s\n", cmd->name);
	i = 0;
	if(!cmd->arguments)
		return ;
	while (cmd->arguments[i])
	{
		printf("Arg %lu: %s\n", i, cmd->arguments[i]);
		i++;
	}
}
