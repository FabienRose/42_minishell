/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/02/2025 17:14:04 by fmixtur           #+#    #+#             */
/*   Updated: 20/02/2025 20:13:22 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "./shell/shell.h"

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
