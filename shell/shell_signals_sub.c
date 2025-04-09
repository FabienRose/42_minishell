/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:23 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:44:07 by kgauthie         ###   ########.fr       */
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
	return (TRUE);
}

t_bool	shell_sig_switchdefault(t_shell *shell)
{
	if (sigaction(SIGINT, &(shell->sint_default), NULL) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	shell_sig_switchkill(t_shell *shell)
{
	(void)shell;
	signal(SIGINT, SIG_DFL);
	return (TRUE);
}
