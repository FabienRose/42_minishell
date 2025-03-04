/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:28:44 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/04 09:30:25 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	set_fd(t_cmd *cmd, t_fd *fd)
{
	fd->saved_stdin = dup(STDIN_FILENO);
	fd->saved_stdout = dup(STDOUT_FILENO);
	if (cmd->pipe_to)
	{
		pipe(fd->pipe_fd);
		dup2(fd->pipe_fd[1], STDOUT_FILENO);
		close(fd->pipe_fd[1]);
		cmd->pipe_to->previous_pipe = fd->pipe_fd[0];
	}
	if (cmd->previous_pipe)
	{
		dup2(cmd->previous_pipe, STDIN_FILENO);
		close(cmd->previous_pipe);
	}
	return (TRUE);
}

t_bool	reset_fd(t_fd *fd)
{
	dup2(fd->saved_stdin, STDIN_FILENO);
	dup2(fd->saved_stdout, STDOUT_FILENO);
	close(fd->saved_stdin);
	close(fd->saved_stdout);
	return (TRUE);
}

t_bool	set_and_execute(t_pmt *pmt)
{
	int		i;
	t_bool	status;
	t_fd	fd;

	i = 0;
	status = PMT_SUCCESS;
	while (pmt->cmds[i])
	{
		if (set_fd(pmt->cmds[i], &fd) == FALSE)
			return (PMT_ERROR);
		if (exec_builtins(pmt->cmds[i], pmt->l_shell) == PMT_SUCCESS)
			status = PMT_SUCCESS;
		else if (exec_cmd(pmt->cmds[i], pmt->l_shell))
			status = PMT_SUCCESS;
		else
			status = PMT_FAILED;
		if (reset_fd(&fd) == FALSE)
			return (PMT_ERROR);
		i++;
	}
	return (status);
}
