/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:58:32 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/02 15:13:58 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int g_onint;

int shell_sig_handler_null(void)
{
	return 0; 
}

t_bool shell_init_sig(t_shell* ptr)
{
	if(!ptr)
		return (FALSE);
	sigemptyset(&(ptr->sint_default.sa_mask));
	sigemptyset(&(ptr->sint_stdin.sa_mask));
	sigemptyset(&(ptr->sint_exec.sa_mask));
	sigemptyset(&(ptr->squit.sa_mask));
	sigaddset(&(ptr->sint_default.sa_mask), SIGINT);
	sigaddset(&(ptr->sint_exec.sa_mask), SIGINT);
	sigaddset(&(ptr->sint_stdin.sa_mask), SIGINT);
	sigaddset(&(ptr->squit.sa_mask), SIGQUIT);
	rl_event_hook=shell_sig_handler_null;
	ptr->sint_default.sa_handler = &shell_sig_handler;
	ptr->sint_exec.sa_handler = &shell_sig_handler_exec;
	ptr->sint_stdin.sa_handler = &shell_sig_handler_stdin;
	ptr->squit.sa_handler = &shell_sig_handler_quit;
	ptr->sint_default.sa_flags = 0;
	ptr->sint_exec.sa_flags = 0;
	ptr->sint_stdin.sa_flags = 0;
	ptr->squit.sa_flags = 0;
	if(sigaction(SIGINT, &(ptr->sint_default), NULL) == -1)
		return (FALSE);
	if(sigaction(SIGQUIT, &(ptr->squit), NULL) == -1)
		return (FALSE);
	return (TRUE);
}
