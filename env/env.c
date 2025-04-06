/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:26:12 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/01 00:26:17 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_bool	update_existing_env(t_shell *minishell, char *variable, char *entry)
{
	int			i;
	int			var_len;
	int			has_equals;

	i = 0;
	var_len = ft_strlen(variable);
	has_equals = ft_strchr(entry, '=') != NULL;
	while (minishell->environment[i])
	{
		if (ft_strncmp(minishell->environment[i], variable, var_len) == 0
			&& (minishell->environment[i][var_len] == '=' || minishell->environment[i][var_len] == '\0'))
		{
			if (!has_equals)
				return (TRUE);
			free(minishell->environment[i]);
			minishell->environment[i] = entry;
			*minishell->original_env = minishell->environment;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	set_environment(t_shell *minishell, char *variable,
			char *value, int value_is_malloc)
{
	int			i;
	char		*entry;

	entry = create_env(variable, value);
	if (value_is_malloc)
		free(value);
	if (!entry)
		return (FALSE);
	if (update_existing_env(minishell, variable, entry))
		return (TRUE);
	i = 0;
	while (minishell->environment[i])
		i++;
	minishell->environment = resize_environ(minishell->environment, i + 2);
	if (!minishell->environment)
	{
		free(entry);
		return (FALSE);
	}
	minishell->environment[i] = entry;
	minishell->environment[i + 1] = NULL;
	*minishell->original_env = minishell->environment;
	return (TRUE);
}

static void	shift_environ(t_shell *minishell, int start)
{
	int			j;

	j = start;
	while (minishell->environment[j + 1])
	{
		minishell->environment[j] = minishell->environment[j + 1];
		j++;
	}
	minishell->environment[j] = NULL;
	*minishell->original_env = minishell->environment;
}

t_bool	unset_environment(t_shell *minishell, char *variable)
{
	int			i;
	int			var_len;

	i = -1;
	var_len = ft_strlen(variable);
	while (minishell->environment[++i])
	{
		if (ft_strncmp(minishell->environment[i], variable, var_len) == 0
			&& (minishell->environment[i][var_len] == '='
			|| minishell->environment[i][var_len] == '\0'))
		{
			free(minishell->environment[i]);
			shift_environ(minishell, i);
			return (TRUE);
		}
	}
	return (FALSE);
}
