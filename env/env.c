/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:39:32 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/25 16:46:41 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_bool	update_existing_env(char **environ, char *variable, char *entry)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], variable, ft_strlen(variable)) == 0
			&& environ[i][ft_strlen(variable)] == '=')
		{
			free(environ[i]);
			environ[i] = entry;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	set_environement(t_shell *minishell, char *variable,
			char *path, int path_is_malloc)
{
	int			i;
	char		*entry;
	extern char	**environ;

	entry = create_env(variable, path);
	if (path_is_malloc)
		free(path);
	if (!entry)
		return (FALSE);
	if (update_existing_env(environ, variable, entry))
		return (TRUE);
	i = 0;
	while (environ[i])
		i++;
	minishell->environement = resize_environ(i + 2);
	if (!minishell->environement)
	{
		free(entry);
		return (FALSE);
	}
	minishell->environement[i] = entry;
	minishell->environement[i + 1] = NULL;
	free_environ(environ);
	environ = minishell->environement;
	return (TRUE);
}

t_bool	unset_environement(t_shell *minishell, char *variable)
{
	int		i;

	i = 0;
	while (minishell->environement[i])
	{
		if (ft_strncmp(minishell->environement[i], variable,
				ft_strlen(variable)) == 0)
		{
			free(minishell->environement[i]);
			minishell->environement[i] = NULL;
			while (minishell->environement[i])
			{
				minishell->environement[i] = minishell->environement[i + 1];
				i++;
			}
			free(minishell->environement[i]);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
