/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:46:03 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/28 14:46:26 by fmixtur          ###   ########.ch       */
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
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
	return (TRUE);
}
