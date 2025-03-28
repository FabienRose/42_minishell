/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_wildcards.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:47:04 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/28 12:47:04 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_bool	wildcard_match(char *name, char *extract)
{
	char	*first_star;
	char	*last_star;
	size_t	prefix_len;
	size_t	suffix_len;
	size_t	name_prefix_len;

	first_star = ft_strchr(extract, '*');
	last_star = ft_strrchr(extract, '*');
	prefix_len = first_star - extract;
	suffix_len = ft_strlen(last_star + 1);
	name_prefix_len = ft_strlen(name) - suffix_len;
	if (prefix_len > 0 && ft_strncmp(name, extract, prefix_len) != 0)
		return (FALSE);
	if (suffix_len > 0 && ft_strncmp(name + name_prefix_len,
			last_star + 1, suffix_len) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	match_arg_push(char ***argument, char *extract)
{
	char			*temp;
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(".");
	if (!dir)
		return (FALSE);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if ((entry->d_name[0] != '.' || extract[0] == '.')
			&& wildcard_match(entry->d_name, extract))
		{
			temp = ft_strdup(entry->d_name);
			if (!temp)
				return (FALSE);
			if (!ft_arraypush_d((void ***)argument, temp))
				return (FALSE);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (TRUE);
}

t_promptret	grp_expand_wildcard(t_grp *grp, char *extract)
{
	char	**argument;
	int		i;

	argument = calloc(1, sizeof(char *));
	if (!argument || !match_arg_push(&argument, extract))
	{
		free(extract);
		return (PMT_ERROR);
	}
	free(extract);
	bubble_sort(argument);
	i = 0;
	while (argument[i])
	{
		if (!cmd_add(grp->cmd, argument[i]))
		{
			free(argument);
			return (PMT_ERROR);
		}
		i++;
	}
	free(argument);
	return (PMT_SUCCESS);
}
