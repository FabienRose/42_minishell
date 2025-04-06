/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:40:13 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:00:47 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directories.h"

static char	*dir_getdisp_w_home(t_dir *dir)
{
	char	*str;
	size_t	pos;

	if (!dir || dir_getlen(dir) < 2)
		return (NULL);
	str = ft_strdup("~");
	if (!str)
		return (NULL);
	pos = 2;
	while (pos < dir_getlen(dir))
	{
		if (!ft_strmerge(&str, "/", dir_getat(dir, pos), NULL))
		{
			free(str);
			return (NULL);
		}
		pos++;
	}
	return (str);
}

char	*dir_getdisp(t_dir *dir)
{
	if (!dir)
		return (NULL);
	if (!PROMPT_DISP_FULL)
		return (ft_strdup(dir->name));
	if (dir_getlen(dir) < 2)
		return (ft_strdup(dir->path));
	if (ft_strncmp(getenv("HOME"), dir->path, ft_strlen(getenv("HOME"))) != 0)
		return (ft_strdup(dir->path));
	return (dir_getdisp_w_home(dir));
}
