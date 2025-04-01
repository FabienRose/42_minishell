/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:39:01 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/29 18:31:42 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	path_loop(char **paths, t_cmd *cmd, t_shell *shell)
{
	int		i;
	char	*cmd_path;
	char	*try_path;

	i = 0;
	while (paths[i])
	{
		try_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(try_path, cmd->name);
		free(try_path);
		execve(cmd_path, cmd->full, shell->environment);
		free(cmd_path);
		i++;
	}
	return (FALSE);
}

t_bool	exec_path(char **paths, t_cmd *cmd, t_shell *shell)
{
	if (cmd->name)
	{
		if (ft_strchr(cmd->name, '/'))
		{
			execve(cmd->name, cmd->full, shell->environment);
			ft_putstr_fd("Minishell: no such file or directory: ", 2);
			ft_putstr_fd(cmd->name, 2);
			ft_putstr_fd("\n", 2);
			return (FALSE);
		}
		path_loop(paths, cmd, shell);
		ft_putstr_fd("Minishell: command not found: ", 2);
		ft_putstr_fd(cmd->name, 2);
		ft_putstr_fd("\n", 2);
	}
	return (FALSE);
}

t_bool	exec_cmd(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;
	char	**paths;

	paths = ft_split(getenv("PATH"), ':');
	if (!paths)
		return (FALSE);
	pid = fork();
	if (pid == -1)
	{
		ft_split_release(&paths);
		return (FALSE);
	}
	if (pid == 0)
	{
		exec_path(paths, cmd, shell);
		ft_split_release(&paths);
		exit(127);
	}
	ft_split_release(&paths);
	waitpid(pid, &status, 0);
	shell->last_return = WEXITSTATUS(status);
	return (TRUE);
}
