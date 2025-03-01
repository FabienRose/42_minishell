/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:23:36 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/01 12:23:36 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

t_bool	unset(t_shell *shell, char **args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
		return (TRUE);
	while (args[i])
	{
		if (is_valid_identifier(args[i]))
			unset_environement(shell, args[i]);
		i++;
	}
	return (TRUE);
}
