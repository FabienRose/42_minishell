/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:17:20 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/31 22:17:35 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_promptret	handle_pipe(t_grp *grp, t_promptret status)
{
	t_fd	pipe_fd;
	pid_t	pid;

	pipe_fd.saved_stdin = dup(STDIN_FILENO);
	pipe_fd.saved_stdout = dup(STDOUT_FILENO);
	if (pipe(pipe_fd.pipe_fd) == -1)
		return (PMT_ERROR);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd.pipe_fd[0]);
		dup2(pipe_fd.pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd.pipe_fd[1]);
		exit(exec_setup(grp->grp_before));
	}
	else
	{
		close(pipe_fd.pipe_fd[1]);
		dup2(pipe_fd.pipe_fd[0], STDIN_FILENO);
		close(pipe_fd.pipe_fd[0]);
		status = exec_setup(grp->grp_after);
		waitpid(pid, NULL, 0);
		reset_fd(&pipe_fd);
	}
	return (status);
}

t_promptret	exec_uniq(t_grp *grp)
{
	pid_t	pid;
	int		return_status;

	pid = fork();
	if (pid == 0)
		exit(exec_setup(grp->grp_uniq));
	waitpid(pid, &return_status, 0);
	return (return_status);
}

t_promptret	handle_token(t_grp *grp)
{
	t_promptret	status;

	status = PMT_SUCCESS;
	if (grp->token->type == TOK_PIPE)
		return (handle_pipe(grp, status));
	else if (grp->token->type == TOK_AND)
	{
		status = exec_setup(grp->grp_before);
		if (((t_shell *)grp->l_shell)->last_return
			== PMT_SUCCESS && grp->grp_after)
			status = exec_setup(grp->grp_after);
	}
	else if (grp->token->type == TOK_OR)
	{
		status = exec_setup(grp->grp_before);
		if (((t_shell *)grp->l_shell)->last_return
			== PMT_FAILED && grp->grp_after)
			status = exec_setup(grp->grp_after);
	}
	return (status);
}

t_promptret	handle_io(t_grp *grp, t_fd *io_fd)
{
	t_promptret	status;

	status = PMT_SUCCESS;
	io_fd->saved_stdin = dup(STDIN_FILENO);
	io_fd->saved_stdout = dup(STDOUT_FILENO);
	if (grp->io->input_stdin[0] || grp->io->input_files[0])
		status = redirect_fd_input(grp);
	if (grp->io->output_files[0] || grp->io->output_endfiles[0])
		status = redirect_fd_output(grp);
	if (status == PMT_ERROR)
		return (PMT_ERROR);
	return (status);
}

t_promptret	exec_setup(t_grp *grp)
{
	t_promptret	status;
	t_fd		io_fd;

	status = PMT_SUCCESS;
	if (grp->io)
		status = handle_io(grp, &io_fd);
	if (grp->cmd && grp->cmd->name && status == PMT_SUCCESS)
	{
		if (exec_builtins(grp->cmd, grp->l_shell) == PMT_SUCCESS)
			status = PMT_SUCCESS;
		else if (exec_cmd(grp->cmd, grp->l_shell))
			status = PMT_SUCCESS;
		else
			status = PMT_FAILED;
	}
	else if (grp->grp_uniq)
		status = exec_uniq(grp);
	if (grp->token)
		status = handle_token(grp);
	if (grp->io)
		reset_fd(&io_fd);
	return (status);
}
