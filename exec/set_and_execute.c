/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace.json                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:15:43 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/27 09:15:43 by fmixtur          ###   ########.ch       */
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
		exit(set_and_execute(grp->grp_before));
	}
	else
	{
		close(pipe_fd.pipe_fd[1]);
		dup2(pipe_fd.pipe_fd[0], STDIN_FILENO);
		close(pipe_fd.pipe_fd[0]);
		status = set_and_execute(grp->grp_after);
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
		exit(set_and_execute(grp->grp_uniq));
	waitpid(pid, &return_status, 0);
	return (return_status);
}

t_promptret	set_and_execute(t_grp *grp)
{
	t_promptret	status;
	t_fd		io_fd;

	status = PMT_SUCCESS;
	//1: GESTION DES REDIRECTIONS
	if (grp->io)
	{
		io_fd.saved_stdin = dup(STDIN_FILENO);
		io_fd.saved_stdout = dup(STDOUT_FILENO);
		if (grp->io->input_files)
			redirect_fd_input(grp);
		if (grp->io->output_files)
			redirect_fd_output(grp);
		if (grp->io->output_endfiles)
			redirect_fd_output(grp);
	}
	//2: GESTION DES COMMANDES
	if (grp->cmd)
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

	//3: GESTION DES OPERATEURS
	if (grp->token)
	{
		if (grp->token->type == TOK_PIPE)
			return (handle_pipe(grp, status));
		else if (grp->token->type == TOK_AND)
		{
			status = set_and_execute(grp->grp_before);
			if (((t_shell *)grp->l_shell)->last_return
				== PMT_SUCCESS && grp->grp_after)
				status = set_and_execute(grp->grp_after);
		}
		else if (grp->token->type == TOK_OR)
		{
			status = set_and_execute(grp->grp_before);
			if (((t_shell *)grp->l_shell)->last_return
				== PMT_FAILED && grp->grp_after)
				status = set_and_execute(grp->grp_after);
		}
	}
	if (grp->io)
		reset_fd(&io_fd);
	return (status);
}

