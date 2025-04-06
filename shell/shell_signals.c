/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:58:32 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:43:36 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	g_onint;

static void	shell_init_sig_p1(t_shell *ptr)
{
	sigemptyset(&(ptr->sint_default.sa_mask));
	sigemptyset(&(ptr->sint_stdin.sa_mask));
	sigemptyset(&(ptr->sint_exec.sa_mask));
	sigaddset(&(ptr->sint_default.sa_mask), SIGINT);
	sigaddset(&(ptr->sint_exec.sa_mask), SIGINT);
	sigaddset(&(ptr->sint_stdin.sa_mask), SIGINT);
}

t_bool	shell_init_sig(t_shell *ptr)
{
	if (!ptr)
		return (FALSE);
	shell_init_sig_p1(ptr);
	ptr->sint_default.sa_handler = &shell_sig_handler;
	ptr->sint_exec.sa_handler = &shell_sig_handler_exec;
	ptr->sint_stdin.sa_handler = &shell_sig_handler_stdin;
	ptr->sint_default.sa_flags = 0;
	ptr->sint_exec.sa_flags = 0;
	ptr->sint_stdin.sa_flags = 0;
	if (sigaction(SIGINT, &(ptr->sint_default), NULL) == -1)
		return (FALSE);
	signal(SIGQUIT, SIG_IGN);
	return (TRUE);
}
