/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:25:46 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/30 21:57:25 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_bool	env_builtins(t_cmd *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd->name, "export", 7) == 0)
	{
		export(shell, cmd->args);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "unset", 6) == 0)
	{
		unset(shell, cmd->args);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "env", 4) == 0)
	{
		print_env(shell, cmd->args);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	cd_builtins(t_cmd *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd->name, "cd", 3) == 0)
	{
		if (!change_directory(shell, cmd->args))
			return (FALSE);
		shell_update_loc(shell);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "pwd", 4) == 0)
	{
		if (!pwd(cmd->args))
			return (FALSE);
		return (TRUE);
	}
	else if (ft_strncmp(cmd->name, "echo", 5) == 0)
	{
		blt_echo(cmd->args);
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
