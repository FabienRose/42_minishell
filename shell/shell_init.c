/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:00:22 by kgauthie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/27 16:03:02 by kgauthie         ###   ########.fr       */
=======
/*   Updated: 2025/02/27 15:29:23 by kgauthie         ###   ########.fr       */
>>>>>>> errerbranch
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

t_bool shell_init(t_shell *shell)
{
	shell->last_error = NULL;
	shell->current_dir = NULL;
<<<<<<< HEAD
	if(!shell_init_sig(shell))
		return (FALSE);
	shell->environement = NULL;
	if(!copy_environ(shell))
		return (FALSE);
	shell->initialized = TRUE;
=======
	shell->initialized = TRUE;
	if(!shell_init_sig(shell))
		return (FALSE);
>>>>>>> errerbranch
	return (TRUE);
}
