/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:52:39 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/07 14:52:39 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	exec_path(char **paths, t_cmd *cmd, t_shell *shell)
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
		execve(cmd_path, cmd_get_fullarray(cmd), shell->environement);
		free(cmd_path);
		i++;
	}
	return (FALSE);
}

t_bool	exec_cmd(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
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
		exit(1);
	}
	ft_split_release(&paths);
	waitpid(pid, NULL, 0);
	return (TRUE);
}
