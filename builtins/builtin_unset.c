/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:54:11 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/01 09:54:11 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

t_bool	builtin_unset(t_shell *shell, char **args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
		return (TRUE);
	while (args[i])
	{
		if (is_valid_identifier(args[i]))
			unset_environment(shell, args[i]);
		i++;
	}
	return (TRUE);
}
