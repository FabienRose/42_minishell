/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:36:46 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/26 17:36:46 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_bool	builtin_pwd(char **arguments)
{
	char	*working_directory;

	if (arguments && arguments[0] && arguments[0][0] == '-' && arguments[0][1])
	{
		ft_putstr_fd("minishell: pwd: -", 2);
		ft_putchar_fd(arguments[0][1], 2);
		ft_putstr_fd(": invalid option\n", 2);
		return (FALSE);
	}
	working_directory = getcwd(NULL, 0);
	if (!working_directory)
	{
		perror("minishell: pwd");
		return (FALSE);
	}
	printf("%s\n", working_directory);
	free(working_directory);
	return (TRUE);
}
