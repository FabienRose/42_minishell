/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:34:56 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/20 10:49:16 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_cmd *cmd_create(void *shell)
{
	t_cmd *ncmd;

	ncmd = ft_calloc(sizeof(t_cmd), 1);
	if(!ncmd)
		return (NULL);
	if(!cmd_init(ncmd, shell))
	{
		cmd_clear(&ncmd);
		return (NULL);
	}
	return ncmd;
}

t_bool cmd_init(t_cmd *cmd, void *shell)
{
	if(!cmd)
		return (FALSE);
	cmd->name = NULL;
	cmd->args = ft_calloc(sizeof(char *), 1);
	if(!cmd->args)
		return (FALSE);
	cmd->full = ft_calloc(sizeof(char *), 1);
	if(!cmd->full)
		return (FALSE);
	cmd->l_shell = shell;
	cmd->var_isset = FALSE;
	cmd->var_name = NULL;
	cmd->var_data = NULL;
	return (TRUE);
}
