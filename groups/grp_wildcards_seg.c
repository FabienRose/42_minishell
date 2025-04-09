/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_wildcards_seg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:31:23 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/09 19:39:53 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_bool	csfinal(char **seg, char *name, int pos)
{
	int	pos_name;
	int	pos_seg;

	pos_name = ft_strlen(name) - 1;
	pos_seg = ft_strlen(seg[pos]) - 1;
	while (pos_name >= 0 && pos_seg >= 0)
	{
		if (name[pos_name] != seg[pos][pos_seg])
			return (FALSE);
		pos_name--;
		pos_seg--;
	}
	return (TRUE);
}

t_bool	check_segments(char **seg, char *name, char *extract)
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
	if (ft_arraylen_d((void **)seg) != 0
		&& extract[ft_strlen(extract) - 1] != '*')
		return (csfinal(seg, name, ft_arraylen_d((void **)seg) - 1));
	return (TRUE);
}
