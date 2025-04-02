/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:57:57 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/02 14:11:04 by kgauthie         ###   ########.fr       */
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
	return (status);
}

t_promptret exec_uniq(t_grp *grp)
{
	pid_t pid;
	int return_status;

	pid = fork();
	if (pid == 0) 
		exit(set_and_execute(grp->grp_uniq));
	waitpid(pid, &return_status, 0);
	return (return_status);
}

t_promptret	set_and_execute(t_grp *grp)
{
	t_promptret	status;

	status = PMT_SUCCESS;
	//1: GESTION DES REDIRECTIONS
	if (grp->io)
	{
		printf("Redirection a implementer.\n");
	}

	//2: GESTION DES COMMANDES
	if (grp->cmd && grp->cmd->name)
	{
		if (exec_builtins(grp->cmd, grp->l_shell) == PMT_SUCCESS)
			status = PMT_SUCCESS;
		status = exec_cmd(grp->cmd, grp->l_shell);
	}
	else if (grp->grp_uniq)
		status = exec_uniq(grp);

	//3: GESTION DES OPERATEURS
	if (grp->token)
	{
		if (grp->token->type == TOK_PIPE)
			return (handle_pipe(grp));
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
	return (status);
}

