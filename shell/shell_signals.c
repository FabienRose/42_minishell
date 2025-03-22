/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:58:32 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/22 15:26:29 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_sig_handler(int sig)
{
	if(sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if(sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \b\b", 1);
	}
}

t_bool shell_init_sig(t_shell* ptr)
{
	if(!ptr)
		return (FALSE);
	ptr->sa.sa_handler = &shell_sig_handler;
	ptr->sa.sa_flags = SA_RESTART;
	sigemptyset(&(ptr->sa.sa_mask));
	sigaddset(&(ptr->sa.sa_mask), SIGINT);
	sigaddset(&(ptr->sa.sa_mask), SIGQUIT);
	if(sigaction(SIGINT, &(ptr->sa), NULL) == -1)
		return (FALSE);
	if(sigaction(SIGQUIT, &(ptr->sa), NULL) == -1)
		return (FALSE);
	return (TRUE);
}