/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals_hdl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:06:29 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/02 15:13:58 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"


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
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	shell_sig_handler_exec(int sig)
{
	if(sig == SIGINT)
	{
		g_onint = 1;
	}
}

void	shell_sig_handler_stdin(int sig)
{
	if(sig == SIGINT)
	{
		g_onint = 1;
		rl_done = 1;
	}
}