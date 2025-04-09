/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:11:54 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 18:54:06 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*my_getenv(const char* var, char **env)
{
	int		i;
	int		var_len;
	char	*value;

	value = NULL;
	var_len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(var, env[i], var_len - 1) == 0 && env[i][var_len] == '=')
		{
			if (ft_strchr(env[i], '='))
				value = ft_strchr(env[i], '=') + 1;
			else
				value = NULL;
		}
		i++;
	}
	return (value);
}

t_bool	copy_environ(t_shell *minishell)
{
	int				i;
	int				size;

	size = 0;
	while ((*minishell->original_env)[size])
		size++;
	minishell->environment = malloc((size + 1) * sizeof(char *));
	if (!minishell->environment)
		return (FALSE);
	i = -1;
	while (++i < size)
	{
		minishell->environment[i] = ft_strdup((*minishell->original_env)[i]);
		if (!minishell->environment[i])
		{
			while (i-- > 0)
				free(minishell->environment[i]);
			free(minishell->environment);
			return (FALSE);
		}
	}
	minishell->environment[size] = NULL;
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

char	**resize_environ(char **environ, int new_size)
{
	char		**new_environ;
	int			i;

	new_environ = ft_calloc(new_size + 1, sizeof(char *));
	if (!new_environ)
		return (NULL);
	i = 0;
	while (environ[i] && i < new_size - 1)
	{
		new_environ[i] = environ[i];
		if (!new_environ[i])
		{
			while (i-- > 0)
				free(new_environ[i]);
			free(new_environ);
			return (NULL);
		}
		i++;
	}
	free(environ);
	return (new_environ);
}
