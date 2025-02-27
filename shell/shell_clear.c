/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:03:05 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/27 16:52:49 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void shell_clear(t_shell *shell)
{
	if(shell->current_dir)
		dir_clear(&(shell->current_dir));
	if(shell->last_error)
	{
		free(shell->last_error);
		shell->last_error = NULL;
	}
	rl_clear_history();
	free_environ(shell->environement);
}