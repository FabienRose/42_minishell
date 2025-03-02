/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:46:31 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/02 12:55:45 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	exec_path(char **paths, char *name, char **args, t_shell *shell)
{
	int		i;
	char	*cmd_path;
	char	*try_path;

	i = 0;
	while (paths[i])
	{
		try_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(try_path, name);
		free(try_path);
		execve(cmd_path, args, shell->environement);
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
		exec_path(paths, pmt->cmds[0]->name, ft_split(pmt->prompt, ' '), shell); // TODO: get name + arguments from t_pmt instead of splitting the prompt
	}
	else
	{
		waitpid(pid, NULL, 0);
		return (TRUE);
	}
	return (FALSE);
}
