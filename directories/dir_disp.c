/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:40:13 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/09 18:45:37 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directories.h"
#include "shell/shell.h"

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

char	*dir_getdisp(t_dir *dir, void *vshell)
{
	t_shell *shell = (t_shell *)vshell;
	if (!dir)
		return (NULL);
	if (!PROMPT_DISP_FULL)
		return (ft_strdup(dir->name));
	if (dir_getlen(dir) < 2)
		return (ft_strdup(dir->path));
	if (ft_strncmp(my_getenv("HOME", shell->environment), dir->path, ft_strlen(my_getenv("HOME", shell->environment))) != 0)
		return (ft_strdup(dir->path));
	return (dir_getdisp_w_home(dir));
}
