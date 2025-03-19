/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:35:02 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 11:08:44 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void cmd_clear_str(void *str)
{
	free(str);
}

void	cmd_clear(t_cmd **cmd)
{
	t_cmd *c_cmd;

	if(cmd && *cmd)
	{
		c_cmd = *cmd;
		if(c_cmd->name)
		{
			free(c_cmd->name);
			c_cmd->name = NULL;
		}
		ft_arrayfree_d((void ***)&(c_cmd->args), &cmd_clear_str);
		ft_arrayfree_d((void ***)&(c_cmd->full), &cmd_clear_str);
		free(c_cmd);
		*cmd = NULL;
	}
}