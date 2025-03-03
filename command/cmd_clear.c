/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:34:33 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/03 16:25:55 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	cmd_release(void *cmd)
{
	cmd_clear((t_cmd **)(&cmd));
}

void	cmd_clear(t_cmd **cmd)
{
	t_cmd *c_cmd = *cmd;
	if(c_cmd->name)
	{
		free(c_cmd->name);
		c_cmd->name = NULL;
	}
	if(c_cmd->arguments)
		ft_split_release(&(c_cmd->arguments));
	ft_arrayfree((void **)&(c_cmd->input_files));
	ft_arrayfree((void **)&(c_cmd->output_files));
	ft_arrayfree((void **)&(c_cmd->output_endfiles));
	ft_arrayfree((void **)&(c_cmd->input_stdin));
	ft_arrayfree((void **)&(c_cmd->full_args));
	if(c_cmd)
	{
		free(c_cmd);
		*cmd = NULL;
	}
}