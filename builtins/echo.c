/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:14:53 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/06 12:14:53 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

static t_bool	check_n_flag(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (FALSE);
	i = 2;
	while (arg[i] == 'n')
		i++;
	if (arg[i])
		return (FALSE);
	return (TRUE);
}

t_bool	echo(char **args)
{
	int		i;
	t_bool	n_flag;

	n_flag = FALSE;
	i = 0;
	if (args[i] && check_n_flag(args[i]))
	{
		n_flag = TRUE;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
	return (TRUE);
}
