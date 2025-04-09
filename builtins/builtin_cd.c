/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:53:46 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 18:37:46 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

char	*define_path(t_shell *shell, char *arg)
{
	char	*path;

	if (!arg || ft_strncmp(arg, "~", 2) == 0)
		path = ft_strdup(my_getenv("HOME", shell->environment));
	else if (ft_strncmp(arg, "~", 1) == 0)
		path = ft_strjoin(my_getenv("HOME", shell->environment), arg + 1);
	else if (ft_strncmp(arg, "-", 2) == 0)
		path = ft_strdup(my_getenv("OLDPWD", shell->environment));
	else if (ft_strncmp(arg, ".", 2) == 0)
		path = ft_strdup(my_getenv("PWD", shell->environment));
	else if (ft_strncmp(arg, "..", 3) == 0)
		path = ft_strjoin(my_getenv("PWD", shell->environment), "/..");
	else
		path = ft_strdup(arg);
	return (path);
}

t_bool	builtin_change_directory(t_shell *shell, char **arg)
{
	char	*path;

	if (arg[1])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		shell->last_return = 1;
		return (FALSE);
	}
	path = define_path(shell, arg[0]);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		perror("");
		shell->last_return = 1;
		free(path);
		return (FALSE);
	}
	set_environment(shell, "OLDPWD", my_getenv("PWD", shell->environment), FALSE);
	set_environment(shell, "PWD", getcwd(NULL, 0), TRUE);
	free(path);
	return (TRUE);
}
