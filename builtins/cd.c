/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:12:15 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/28 13:01:17 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

char	*define_path(char *arg)
{
	char	*path;

	if (!arg || ft_strncmp(arg, "~", 2) == 0)
		path = ft_strdup(getenv("HOME"));
	else if (ft_strncmp(arg, "~", 1) == 0)
		path = ft_strjoin(getenv("HOME"), arg + 1);
	else if (ft_strncmp(arg, "-", 2) == 0)
		path = ft_strdup(getenv("OLDPWD"));
	else if (ft_strncmp(arg, ".", 2) == 0)
		path = ft_strdup(getenv("PWD"));
	else if (ft_strncmp(arg, "..", 3) == 0)
		path = ft_strjoin(getenv("PWD"), "/..");
	else
		path = ft_strdup(arg);
	return (path);
}

t_bool	change_directory(t_shell *shell, char **arg)
{
	char	*path;

	if (arg[1])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (FALSE);
	}
	path = define_path(arg[0]);
	if (chdir(path) == -1)
	{
		perror(ft_strjoin("minishell: cd: ", path));
		free(path);
		return (FALSE);
	}
	set_environement(shell, "OLDPWD", getenv("PWD"), FALSE);
	set_environement(shell, "PWD", getcwd(NULL, 0), TRUE);
	free(path);
	return (TRUE);
}
