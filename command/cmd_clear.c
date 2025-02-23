/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:34:33 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/23 17:40:30 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

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
	if(c_cmd)
	{
		free(c_cmd);
		*cmd = NULL;
	}
}