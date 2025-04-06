/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:35:02 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:33:40 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void	cmd_clear_str(void *str)
{
	free(str);
}

void	cmd_clear(t_cmd **cmd)
{
	t_cmd	*c_cmd;

	if (cmd && *cmd)
	{
		c_cmd = *cmd;
		if (c_cmd->name)
		{
			free(c_cmd->name);
			c_cmd->name = NULL;
		}
		if (c_cmd->var_name)
		{
			free(c_cmd->var_name);
			c_cmd->var_name = NULL;
		}
		if (c_cmd->var_data)
		{
			free(c_cmd->var_data);
			c_cmd->var_data = NULL;
		}
		ft_arrayfree_d((void ***)&(c_cmd->args), &cmd_clear_str);
		ft_arrayfree_d((void ***)&(c_cmd->full), &cmd_clear_str);
		free(c_cmd);
		*cmd = NULL;
	}
}
