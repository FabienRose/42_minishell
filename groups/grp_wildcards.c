/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_wildcards.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:42:40 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/28 20:53:49 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_bool	check_segments(char **seg, char *name, char *extract)
{
	char	*pos;
	int		i;

	pos = name;
	i = 0;
	while (seg[i])
	{
		if (i == 0 && extract[0] != '*' && ft_strncmp(name, seg[0],
				ft_strlen(seg[0])) != 0)
			return (FALSE);
		if (i == 0 && extract[0] != '*')
			pos += ft_strlen(seg[0]);
		else
		{
			pos = ft_strnstr(pos, seg[i], ft_strlen(pos));
			if (!pos)
				return (FALSE);
			pos += ft_strlen(seg[i]);
		}
		i++;
	}
	if (i > 0 && extract[ft_strlen(extract) - 1] != '*' && *pos != '\0')
		return (FALSE);
	return (TRUE);
}

t_bool	wildcard_match(char *name, char *extract)
{
	char	**segments;
	t_bool	result;

	segments = ft_split(extract, '*');
	if (!segments)
		return (FALSE);
	result = check_segments(segments, name, extract);
	ft_split_release(&segments);
	return (result);
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
