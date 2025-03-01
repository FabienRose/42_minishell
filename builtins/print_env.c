/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:38:17 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/01 12:38:40 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

t_bool	print_env(t_shell *shell, char **args)
{
	int	i;

	if (args && args[0])
	{
		ft_putstr_fd("No arguments / options allowed\n", 2);
		return (FALSE);
	}
	if (!shell->environement)
	{
		ft_putstr_fd("No environment variables set\n", 2);
		return (FALSE);
	}
	i = 0;
	while (shell->environement[i])
	{
		printf("%s\n", shell->environement[i]);
		i++;
	}
	return (TRUE);
}
