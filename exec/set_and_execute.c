/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:06:55 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/26 01:06:55 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_promptret handle_pipe(t_grp *grp)
{
	t_promptret status;
	t_fd fd;
	pid_t pid;

	fd.saved_stdin = dup(STDIN_FILENO);
	fd.saved_stdout = dup(STDOUT_FILENO);
	if (pipe(fd.pipe_fd) == -1)
		return (PMT_ERROR);
	pid = fork();
	if (pid == 0) 
	{
		close(fd.pipe_fd[0]);
		dup2(fd.pipe_fd[1], STDOUT_FILENO);
		close(fd.pipe_fd[1]);
		exit(set_and_execute(grp->grp_before));
	}
	else 
	{
		close(fd.pipe_fd[1]);
		dup2(fd.pipe_fd[0], STDIN_FILENO);
		close(fd.pipe_fd[0]);
		status = set_and_execute(grp->grp_after);
		waitpid(pid, NULL, 0);
		reset_fd(&fd);
	}
	return status;
}

t_promptret exec_uniq(t_grp *grp)
{
	pid_t pid;
	int return_status;

	pid = fork();
        if (pid == 0) 
            exit(set_and_execute(grp->grp_uniq));
        waitpid(pid, &return_status, 0);
	return return_status;
}

t_promptret	set_and_execute(t_grp *grp)
{
	t_promptret	status;
	
	status = PMT_SUCCESS;
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

	if (grp->token)
	{
		if (grp->token->type == TOK_PIPE)
			return handle_pipe(grp);
		else if (grp->token->type == TOK_AND)
		{
			status = set_and_execute(grp->grp_before);
			if (status == PMT_SUCCESS && grp->grp_after)
				status = set_and_execute(grp->grp_after);
		}
		else if (grp->token->type == TOK_OR)
		{
			status = set_and_execute(grp->grp_before);
			if (status == PMT_FAILED && grp->grp_after)
				status = set_and_execute(grp->grp_after);
		}
	}
	return (status);
}

