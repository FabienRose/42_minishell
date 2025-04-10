/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals_hdl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:16:50 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/10 16:16:50 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	shell_sig_handler_exec(int sig)
{
	if (sig == SIGINT)
	{
		g_onint = 1;
	}
}

void	shell_sig_handler_stdin(int sig)
{
	if (sig == SIGINT)
	{
		g_onint = 1;
	}
}

void	shell_sig_handler_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
		g_onint = 2;
	}
}
