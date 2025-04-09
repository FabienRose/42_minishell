/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:41:12 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 20:15:34 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

t_bool	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i])
			&& str[i] != '-'
			&& str[i] != '+')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_promptret	builtin_exit_sub(t_shell *shell, char **args)
{
	if (!is_numeric(args[0]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		shell->last_return = 2;
		return (PMT_STOP);
	}
	shell->last_return = ft_atoi(args[0]);
	return (PMT_STOP);
}

t_promptret	builtin_exit(t_shell *shell, char **args)
{
	int	len;

	len = ft_arraylen_d((void **)args);
	printf("exit\n");
	if (len == 0)
	{
		shell->last_return = 0;
		return (PMT_STOP);
	}
	if (len > 1)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd("too many arguments\n", 2);
		shell->last_return = 1;
		return (PMT_SUCCESS);
	}
	if (len == 1)
		return (builtin_exit_sub(shell, args));
	return (PMT_FAILED);
}
