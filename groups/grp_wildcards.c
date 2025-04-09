/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_wildcards.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:42:40 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 19:40:20 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

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

static t_promptret	grp_expand_wildcard_extended(t_grp *grp, char ***argument)
{
	char	*current;
	int		i;

	bubble_sort((*argument));
	i = 0;
	while ((*argument)[i])
	{
		current = ft_strdup((*argument)[i]);
		if (!current || !cmd_add(grp->cmd, current))
		{
			ft_split_release(argument);
			return (PMT_ERROR);
		}
		i++;
	}
	ft_split_release(argument);
	return (PMT_SUCCESS);
}

t_promptret	grp_expand_wildcard(t_grp *grp, char *extract)
{
	char	**argument;

	argument = ft_calloc(1, sizeof(char *));
	if (!argument || !match_arg_push(&argument, extract))
	{
		free(extract);
		return (PMT_ERROR);
	}
	if (ft_arraylen_d((void **)argument) == 0)
	{
		free(argument);
		if (!cmd_add(grp->cmd, extract))
			return (PMT_ERROR);
		return (PMT_SUCCESS);
	}
	free(extract);
	return (grp_expand_wildcard_extended(grp, &argument));
}
