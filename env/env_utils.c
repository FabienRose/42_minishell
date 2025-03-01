/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:10:06 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/28 15:10:06 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_bool	copy_environ(t_shell *minishell)
{
	extern char		**environ;
	int				i;
	int				size;

	size = 0;
	while (environ[size])
		size++;
	minishell->environement = malloc((size + 1) * sizeof(char *));
	if (!minishell->environement)
		return (FALSE);
	i = -1;
	while (++i < size)
	{
		minishell->environement[i] = ft_strdup(environ[i]);
		if (!minishell->environement[i])
		{
			while (i-- > 0)
				free(minishell->environement[i]);
			free(minishell->environement);
			return (FALSE);
		}
	}
	minishell->environement[size] = NULL;
	environ = minishell->environement;
	return (TRUE);
}

t_bool	free_environ(char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		free(environ[i]);
		i++;
	}
	free(environ);
	return (TRUE);
}

char	*create_env(char *variable, char *value)
{
	char	*entry;
	size_t	len;
	int		i;
	int		j;

	if (value)
		len = ft_strlen(variable) + ft_strlen(value) + 2;
	else
		len = ft_strlen(variable) + 1;
	entry = ft_calloc(1, len);
	if (!entry)
		return (NULL);
	i = -1;
	while (variable[++i])
		entry[i] = variable[i];
	if (value)
	{
		entry[i++] = '=';
		j = 0;
		while (value[j])
			entry[i++] = value[j++];
	}
	return (entry);
}

char	**resize_environ(int new_size)
{
	extern char	**environ;
	char		**new_environ;
	int			i;

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
