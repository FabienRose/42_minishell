/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:00:14 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 17:03:10 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_bool	env_builtins(t_cmd *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd->name, "export", 7) == 0)
	{
		builtin_export(shell, cmd->args);
		shell->last_return = 0;
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "unset", 6) == 0)
	{
		builtin_unset(shell, cmd->args);
		shell->last_return = 0;
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "env", 4) == 0)
	{
		print_env(shell, cmd->args);
		shell->last_return = 0;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	cd_builtins(t_cmd *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd->name, "cd", 3) == 0)
	{
		if (!builtin_change_directory(shell, cmd->args))
			return (TRUE);
		shell->last_return = 0;
		shell_update_loc(shell);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "pwd", 4) == 0)
	{
		if (!builtin_pwd(cmd->args))
		{
			shell->last_return = 1;
			return (FALSE);
		}
		shell->last_return = 0;
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "echo", 5) == 0)
	{
		builtin_echo(cmd->args);
		shell->last_return = 0;
		return (TRUE);
	}
	return (FALSE);
}

t_promptret	exec_builtins(t_cmd *cmd, t_shell *shell)
{
	int		status;

	if (env_builtins(cmd, shell))
		status = PMT_SUCCESS;
	else if (cd_builtins(cmd, shell))
		status = PMT_SUCCESS;
	else if (strncmp(cmd->name, "exit", 5) == 0)
		status = PMT_STOP;
	else
		status = PMT_FAILED;
	return (status);
}
