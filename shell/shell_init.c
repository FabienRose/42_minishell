/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:00:22 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:42:32 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bool	shell_init(t_shell *shell, char ***environ)
{
	shell->last_error = NULL;
	shell->current_dir = NULL;
	if (!shell_init_sig(shell))
		return (FALSE);
	shell->environment = NULL;
	shell->original_env = environ;
	if (!copy_environ(shell))
		return (FALSE);
	shell->initialized = TRUE;
	shell->last_return = 0;
	g_onint = 0;
	return (TRUE);
}
