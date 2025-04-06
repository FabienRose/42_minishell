/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:02:09 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 14:58:02 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directories.h"

static void	dir_clear_detailed(t_dir *dir)
{
	size_t	i;

	if (dir->detailed_path)
	{
		i = 0;
		while (dir->detailed_path[i])
		{
			free(dir->detailed_path[i]);
			dir->detailed_path[i] = (NULL);
			i++;
		}
		free(dir->detailed_path);
		dir->detailed_path = NULL;
	}
}

void	dir_clear(t_dir **dir)
{
	t_dir	*cdir;

	cdir = *dir;
	if (!cdir)
		return ;
	if (cdir->name)
	{
		free(cdir->name);
		cdir->name = NULL;
	}
	if (cdir->path)
	{
		free(cdir->path);
		cdir->path = NULL;
	}
	dir_clear_detailed(cdir);
	free(cdir);
	*dir = NULL;
}
