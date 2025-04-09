/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:22:11 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 18:42:11 by kgauthie         ###   ########.fr       */
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

t_promptret	handle_child_process(t_cmd *cmd, t_shell *shell, char **paths)
{
	exec_path(paths, cmd, shell);
	ft_split_release(&paths);
	shell->last_return = 127;
	return (PMT_STOP);
}

t_promptret	exec_cmd(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		ret;
	char	**paths;

	paths = ft_split(my_getenv("PATH", shell->environment), ':');
	if (!paths)
		return (PMT_ERROR);
	pid = fork();
	if (pid == -1)
	{
		ft_split_release(&paths);
		return (PMT_ERROR);
	}
	if (pid == 0)
		return (handle_child_process(cmd, shell, paths));
	ft_split_release(&paths);
	waitpid(pid, &ret, 0);
	shell->last_return = WEXITSTATUS(ret);
	if (shell->last_return == 0)
		return (PMT_SUCCESS);
	else
		return (PMT_FAILED);
}
