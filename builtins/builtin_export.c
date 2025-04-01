/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:53:51 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/01 09:53:51 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell/shell.h"

t_bool	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !*str || (!ft_isalpha(*str) && *str != '_'))
		return (FALSE);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char	**create_sorted_array(t_shell *shell)
{
	char	**sorted;
	int		i;

	i = 0;
	while (shell->environment[i])
		i++;
	sorted = ft_calloc(sizeof(char *), i + 1);
	if (!sorted)
		return (NULL);
	i = 0;
	while (shell->environment[i])
	{
		sorted[i] = ft_strdup(shell->environment[i]);
		if (!sorted[i])
		{
			free_environ(sorted);
			return (NULL);
		}
		i++;
	}
	bubble_sort(sorted);
	return (sorted);
}

void	print_sorted_env(t_shell *shell)
{
	char	**sorted;
	char	*equal;
	int		i;

	sorted = create_sorted_array(shell);
	if (!sorted)
		return ;
	i = 0;
	while (sorted[i])
	{
		equal = ft_strchr(sorted[i], '=');
		if (equal)
		{
			*equal = '\0';
			printf("declare -x %s=\"%s\"\n", sorted[i], equal + 1);
			*equal = '=';
		}
		else
			printf("declare -x %s\n", sorted[i]);
		free(sorted[i]);
		i++;
	}
	free(sorted);
}

t_bool	add_env(t_shell *shell, char *arg)
{
	char	*equal_sign;
	char	*var_name;
	t_bool	ret;

	equal_sign = ft_strchr(arg, '=');
	if (!equal_sign)
		return (set_environment(shell, arg, NULL, FALSE));
	var_name = ft_substr(arg, 0, equal_sign - arg);
	if (!var_name)
		return (FALSE);
	ret = set_environment(shell, var_name, equal_sign + 1, FALSE);
	free(var_name);
	return (ret);
}

t_bool	builtin_export(t_shell *shell, char **arg)
{
	int	i;

	i = 0;
	(void)shell;
	if (!arg[i])
	{
		print_sorted_env(shell);
		return (TRUE);
	}
	while (arg[i])
	{
		if (!is_valid_identifier(arg[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
		else
			add_env(shell, arg[i]);
		i++;
	}
	return (TRUE);
}
