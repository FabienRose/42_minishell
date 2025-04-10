/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:19:50 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/10 16:19:50 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	reset_fd(t_fd *fd)
{
	if (dup2(fd->saved_stdin, STDIN_FILENO) == -1)
		return (FALSE);
	if (dup2(fd->saved_stdout, STDOUT_FILENO) == -1)
		return (FALSE);
	close(fd->saved_stdin);
	close(fd->saved_stdout);
	return (TRUE);
}

t_bool	file_error(char *file, t_grp *grp)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	perror(": ");
	((t_shell *)grp->l_shell)->last_return = 1;
	return (FALSE);
}
