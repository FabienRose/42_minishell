/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:39:22 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:01:14 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directories.h"

t_dir	*dir_new(const char *path)
{
	t_dir	*ndir;

	ndir = ft_calloc(sizeof(t_dir), 1);
	if (!ndir)
		return (NULL);
	if (!dir_init_from_path(ndir, path))
	{
		dir_clear(&ndir);
		return (NULL);
	}
	return (ndir);
}

t_bool	dir_init_from_path(t_dir *dir, const char *path)
{
	if (ft_strlen(path) == 0)
		return (FALSE);
	if (!dir)
		return (FALSE);
	dir->path = ft_strdup(path);
	if (!dir->path)
		return (FALSE);
	dir->detailed_path = ft_split(path, '/');
	if (!dir->detailed_path)
		return (FALSE);
	if (dir_getlen(dir) == 0)
		dir->name = ft_strdup("/");
	else
		dir->name = ft_strdup(dir_getat(dir, dir_getlen(dir) - 1));
	if (!dir->name)
		return (FALSE);
	return (TRUE);
}
