/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:58:32 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/27 12:45:38 by kgauthie         ###   ########.fr       */
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
}

t_bool shell_init_sig(t_shell* ptr)
{
	if(!ptr)
		return (FALSE);
	ptr->sa.sa_handler = &shell_sig_handler;
	ptr->sa.sa_flags = 0;
	sigemptyset(&(ptr->sa.sa_mask));
	sigaddset(&(ptr->sa.sa_mask), SIGINT);
	sigaction(SIGINT, &(ptr->sa), NULL);
	return (TRUE);
}