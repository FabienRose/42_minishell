/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:28:33 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/22 16:28:33 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

t_bool	change_directory(t_shell minishell, char *arguments)
{
	char	*path;

	(void)minishell;
	path = NULL;
	if (!arguments || ft_strncmp(arguments, "~", 2) == 0)
		path = getenv("HOME");
	chdir(path);
	return (TRUE);
}
