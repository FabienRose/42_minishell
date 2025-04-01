/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:58:32 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/01 15:34:54 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int gv_onint;

int shell_sig_handler_null(void)
{
	return 0; 
}


void	shell_sig_handler_quit (int sig)
{
	if(sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \b\b", 1);
	}
}

void	shell_sig_handler(int sig)
{
	if(sig == SIGINT)
	{
		write(STDIN_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	shell_sig_handler_stdin(int sig)
{
	if(sig == SIGINT)
	{
		gv_onint = 1;
		rl_done = 1;
	}
}

t_bool shell_init_sig(t_shell* ptr)
{
	if(!ptr)
		return (FALSE);
	sigemptyset(&(ptr->sint_default.sa_mask));
	sigemptyset(&(ptr->sint_stdin.sa_mask));
	sigemptyset(&(ptr->squit.sa_mask));
	sigaddset(&(ptr->sint_default.sa_mask), SIGINT);
	sigaddset(&(ptr->sint_stdin.sa_mask), SIGINT);
	sigaddset(&(ptr->squit.sa_mask), SIGQUIT);
	rl_event_hook=shell_sig_handler_null;
	ptr->sint_default.sa_handler = &shell_sig_handler;
	ptr->sint_stdin.sa_handler = &shell_sig_handler_stdin;
	ptr->squit.sa_handler = &shell_sig_handler_quit;
	ptr->sint_default.sa_flags = 0;
	ptr->sint_stdin.sa_flags = 0;
	ptr->squit.sa_flags = 0;
	if(sigaction(SIGINT, &(ptr->sint_default), NULL) == -1)
		return (FALSE);
	if(sigaction(SIGQUIT, &(ptr->squit), NULL) == -1)
		return (FALSE);
	return (TRUE);
}
