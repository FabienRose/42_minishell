/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:27:01 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/23 11:27:24 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

extern char	**environ;

char	*create_env(char *variable, char *value)
{
	char	*entry;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(variable) + ft_strlen(value) + 2;
	entry = ft_calloc(1, len);
	if (!entry)
		return (NULL);
	i = 0;
	while (variable[i])
	{
		entry[i] = variable[i];
		i++;
	}
	entry[i++] = '=';
	j = 0;
	while (value[j])
	{
		entry[i++] = value[j++];
	}
	return (entry);
}

char	**resize_environ(int new_size)
{
	char	**new_environ;
	int		i;

	new_environ = ft_calloc(new_size + 1, sizeof(char *));
	if (!new_environ)
		return (NULL);
	i = 0;
	while (environ[i] && i < new_size - 1)
	{
		new_environ[i] = ft_strdup(environ[i]);
		if (!new_environ[i])
		{
			while (i-- > 0)
			free(new_environ[i]);
			free(new_environ);
			return (NULL);
		}
		i++;
	}
	return (new_environ);
}

t_bool	set_environement(t_shell *minishell ,char *variable, char *path)
{
	int		i;
	char	*entry;
	
	entry = create_env(variable, path);
	if (!entry)
	return (FALSE);
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
	minishell->environement = resize_environ(i + 2);
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
