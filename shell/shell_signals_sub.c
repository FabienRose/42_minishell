/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:17:06 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/10 16:17:06 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bool	shell_sig_switchstdin(t_shell *shell)
{
	if (sigaction(SIGINT, &(shell->sint_stdin), NULL) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	shell_sig_switchexec(t_shell *shell)
{
	if (sigaction(SIGINT, &(shell->sint_exec), NULL) == -1)
		return (FALSE);
	if (sigaction(SIGQUIT, &(shell->squit), NULL) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	shell_sig_switchdefault(t_shell *shell)
{
	if (sigaction(SIGINT, &(shell->sint_default), NULL) == -1)
		return (FALSE);
	signal(SIGQUIT, SIG_IGN);
	return (TRUE);
}

t_bool	shell_sig_switchkill(t_shell *shell)
{
	(void)shell;
	signal(SIGINT, SIG_DFL);
	return (TRUE);
}

t_bool	shell_sig_switch_quit(t_shell *shell)
{
	(void)shell;
	signal(SIGQUIT, SIG_DFL);
	return (TRUE);
}
