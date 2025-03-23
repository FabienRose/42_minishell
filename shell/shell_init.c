/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:00:22 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/22 15:57:58 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

t_bool shell_init(t_shell *shell)
{
	shell->last_error = NULL;
	shell->current_dir = NULL;
	if(!shell_init_sig(shell))
		return (FALSE);
	shell->environement = NULL;
	if(!copy_environ(shell))
		return (FALSE);
	shell->initialized = TRUE;
	shell->last_return = 0;
	return (TRUE);
}
