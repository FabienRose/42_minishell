/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:11:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/27 16:44:04 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

t_bool	unset(t_shell *shell, char *args)
{
	if (!args)
		return (FALSE);
	if (!is_valid_identifier(args))
		return (FALSE);
	unset_environement(shell, args);
	return (TRUE);
}
