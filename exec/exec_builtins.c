/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:48:29 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/06 11:52:12 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_bool	env_builtins(t_cmd *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd->name, "export", 7) == 0)
	{
		export(shell, cmd->arguments);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "unset", 6) == 0)
	{
		unset(shell, cmd->arguments);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "env", 4) == 0)
	{
		print_env(shell, cmd->arguments);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	cd_builtins(t_cmd *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd->name, "cd", 3) == 0)
	{
		if (!change_directory(shell, cmd->arguments))
			return (FALSE);
		shell_update_loc(shell);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "pwd", 4) == 0)
	{
		if (!pwd(cmd->arguments))
			return (FALSE);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "echo", 5) == 0)
	{
		echo(cmd->arguments);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	exec_builtins(t_cmd *cmd, t_shell *shell)
{
	int		status;

	if (env_builtins(cmd, shell))
		status = PMT_SUCCESS;
	else if (cd_builtins(cmd, shell))
		status = PMT_SUCCESS;
	else
		status = PMT_FAILED;
	return (status);
}
