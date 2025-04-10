/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:54:09 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/10 14:54:09 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	g_onint;

static void	shell_init_sig_p1(t_shell *ptr)
{
	sigemptyset(&(ptr->sint_default.sa_mask));
	sigemptyset(&(ptr->sint_stdin.sa_mask));
	sigemptyset(&(ptr->sint_exec.sa_mask));
	sigemptyset(&(ptr->squit.sa_mask));
	sigaddset(&(ptr->sint_default.sa_mask), SIGINT);
	sigaddset(&(ptr->sint_exec.sa_mask), SIGINT);
	sigaddset(&(ptr->sint_stdin.sa_mask), SIGINT);
	sigaddset(&(ptr->squit.sa_mask), SIGQUIT);
}

t_bool	shell_init_sig(t_shell *ptr)
{
	if (!ptr)
		return (FALSE);
	shell_init_sig_p1(ptr);
	ptr->sint_default.sa_handler = &shell_sig_handler;
	ptr->sint_exec.sa_handler = &shell_sig_handler_exec;
	ptr->sint_stdin.sa_handler = &shell_sig_handler_stdin;
	ptr->squit.sa_handler = &shell_sig_handler_quit;
	ptr->sint_default.sa_flags = 0;
	ptr->sint_exec.sa_flags = 0;
	ptr->sint_stdin.sa_flags = 0;
	ptr->squit.sa_flags = 0;
	if (sigaction(SIGINT, &(ptr->sint_default), NULL) == -1)
		return (FALSE);
	signal(SIGQUIT, SIG_IGN);
	return (TRUE);
}
