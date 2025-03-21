/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:52:39 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/21 16:27:09 by kgauthie         ###   ########.fr       */
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
	int 	status;
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
	printf("Exit status: %i\n", WEXITSTATUS(status));
	return (TRUE);
}
