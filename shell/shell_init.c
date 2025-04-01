/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:13:34 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/01 00:13:34 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

t_bool shell_init(t_shell *shell, char ***environ)
{
	shell->last_error = NULL;
	shell->current_dir = NULL;
	if(!shell_init_sig(shell))
		return (FALSE);
	shell->environment = NULL;
	shell->original_env = environ;
	if(!copy_environ(shell))
		return (FALSE);
	shell->initialized = TRUE;
	shell->last_return = 0;
	return (TRUE);
}
