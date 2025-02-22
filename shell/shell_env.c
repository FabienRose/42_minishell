/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:15 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/22 10:01:12 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_bool shell_gethead_check(t_shell *shell, char **str, char **dir)
{
	if(!shell->current_dir)
		return (FALSE);
	*dir = dir_getdisp(shell->current_dir);
	if(!(*dir))
		return (FALSE);
	*str = ft_strdup("");
	if(!(*str))
	{
		free(*dir);
		return (FALSE);
	}
	return (TRUE);
}

char *shell_gethead(t_shell *shell)
{
	char *str;
	char *dir;

	if(!shell_gethead_check(shell, &str, &dir))
		return (NULL);
	if(!ft_strmerge(&str, FONT_BOLD, PROMPT_USER_COL, getenv("USER"))
		|| !ft_strmerge(&str, FONT_NRM, "@", NULL)
		|| !ft_strmerge(&str, FONT_BOLD, PROMPT_NAME_COL, getenv("NAME"))
		|| !ft_strmerge(&str, FONT_NRM, ":", NULL)
		|| !ft_strmerge(&str, FONT_BOLD, FONT_BLU, dir)
		|| !ft_strmerge(&str, FONT_NRM, "$ ", NULL)
	)
	{
		free(dir);
		free(str);
		return (NULL);
	}
	free(dir);
	return str;		
}

t_bool shell_update_loc(t_shell *shell)
{
	t_dir *ndir;

	ndir = dir_new(getenv("PWD"));
	if(!ndir)
		return (FALSE);
	if(shell->current_dir)
		dir_clear(&(shell->current_dir));
	shell->current_dir = ndir;
	return (TRUE);
}