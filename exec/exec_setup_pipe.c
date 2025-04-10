/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setup_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:36:26 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/10 16:41:45 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_promptret	handle_pipe_sub(t_grp *grp, t_promptret status,
	t_fd pipe_fd, int pid)
{
	close(pipe_fd.pipe_fd[1]);
	if (dup2(pipe_fd.pipe_fd[0], STDIN_FILENO) == -1)
		return (PMT_ERROR);
	close(pipe_fd.pipe_fd[0]);
	status = exec_setup(grp->grp_after);
	waitpid(pid, NULL, 0);
	if (!reset_fd(&pipe_fd))
		return (PMT_ERROR);
	return (status);
}

t_promptret	handle_pipe(t_grp *grp, t_promptret status)
{
	t_fd	pipe_fd;
	pid_t	pid;

	status = save_fd(&pipe_fd);
	if (status != PMT_SUCCESS)
		return (status);
	if (pipe(pipe_fd.pipe_fd) == -1)
		return (PMT_ERROR);
	pid = fork();
	if (pid == -1)
		return (PMT_ERROR);
	if (pid == 0)
	{
		shell_sig_switch_quit(grp->l_shell);
		close(pipe_fd.pipe_fd[0]);
		if (dup2(pipe_fd.pipe_fd[1], STDOUT_FILENO) == -1)
			return (PMT_ERROR);
		close(pipe_fd.pipe_fd[1]);
		exec_setup(grp->grp_before);
		return (PMT_STOP);
	}
	return (handle_pipe_sub(grp, status, pipe_fd, pid));
}
