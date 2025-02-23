/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:10:19 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/23 20:13:08 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

t_bool	echo(t_shell *shell, char *args)
{
	t_bool	n_option;
	char	*msg;

	(void)shell;
	n_option = FALSE;
	if (!args)
	{
		printf("\n");
		return (TRUE);
	}
	if (ft_strncmp(args, "-n", 2) == 0 && (args[2] == ' ' || args[2] == '\0'))
	{
		n_option = TRUE;
		args += 2;
		while (*args == ' ')
			args++;
	}
	msg = args;
	printf("%s", msg);
	if (!n_option)
		printf("\n");
	return (TRUE);
}
