/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:51:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/27 16:43:47 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

t_bool	echo(t_shell *shell, char *args)
{
	int		i;
	t_bool	n_flag;

	(void)shell;
	n_flag = FALSE;
	i = 0;
	while (args[i] == '-')
	{
		i++;
		while (args[i] == 'n')
			i++;
		if (args[i] == ' ' || args[i] == '\0')
		{
			while (args[i] == ' ')
				i++;
			n_flag = TRUE;
		}
		else
			i = 0;
	}
	ft_putstr_fd(args + i, 1);
	if (!n_flag)
		write(1, "\n", 1);
	return (TRUE);
}
