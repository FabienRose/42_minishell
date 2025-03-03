/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:04:28 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/03 11:07:22 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	exec_path(char **paths, t_pmt *pmt, t_shell *shell)
{
	int		i;
	char	*cmd_path;
	char	*try_path;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (FALSE);
	i = 0;
	while (paths[i])
	{
		try_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(try_path, pmt->cmds[0]->name);
		free(try_path);
		execve(cmd_path, pmt->cmds[0]->arguments, shell->environement);
		free(cmd_path);
		i++;
	}
	return (FALSE);
}

t_bool	exec_cmd(t_pmt *pmt, t_shell *shell)
{
	pid_t	pid;
	char	**paths;
	int		pipe_fd[2];

	paths = ft_split(getenv("PATH"), ':');
	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
		return (FALSE);

	if (pid == 0)
	{
		exec_path(paths, pmt, shell);
	}
	else
	{
		waitpid(pid, NULL, 0);
		return (TRUE);
	}
	return (FALSE);
}
