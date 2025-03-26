/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:21:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/25 15:34:36 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_bool	update_existing_env(char **env_copy, char *variable, char *entry)
{
	int			i;
	int			var_len;
	int			has_equals;
	extern char	**environ;

	i = 0;
	var_len = ft_strlen(variable);
	has_equals = ft_strchr(entry, '=') != NULL;
	while (env_copy[i])
	{
		if (ft_strncmp(env_copy[i], variable, var_len) == 0
			&& (env_copy[i][var_len] == '=' || env_copy[i][var_len] == '\0'))
		{
			if (!has_equals)
				return (TRUE);
			free(env_copy[i]);
			env_copy[i] = entry;
			environ = env_copy;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	set_environement(t_shell *minishell, char *variable,
			char *value, int path_is_malloc)
{
	int			i;
	char		*entry;
	extern char	**environ;

	entry = create_env(variable, value);
	if (path_is_malloc)
		free(value);
	if (!entry)
		return (FALSE);
	if (update_existing_env(minishell->environement, variable, entry))
		return (TRUE);
	i = 0;
	while (minishell->environement[i])
		i++;
	minishell->environement = resize_environ(minishell->environement, i + 2);
	if (!minishell->environement)
	{
		free(entry);
		return (FALSE);
	}
	minishell->environement[i] = entry;
	minishell->environement[i + 1] = NULL;
	environ = minishell->environement;
	return (TRUE);
}

static void	shift_environ(t_shell *minishell, int start)
{
	int			j;
	extern char	**environ;

	j = start;
	while (minishell->environement[j + 1])
	{
		minishell->environement[j] = minishell->environement[j + 1];
		j++;
	}
	minishell->environement[j] = NULL;
	environ = minishell->environement;
}

t_bool	unset_environement(t_shell *minishell, char *variable)
{
	int			i;
	int			var_len;

	i = -1;
	var_len = ft_strlen(variable);
	while (minishell->environement[++i])
	{
		if (ft_strncmp(minishell->environement[i], variable, var_len) == 0
			&& (minishell->environement[i][var_len] == '='
			|| minishell->environement[i][var_len] == '\0'))
		{
			free(minishell->environement[i]);
			shift_environ(minishell, i);
			return (TRUE);
		}
	}
	return (FALSE);
}
