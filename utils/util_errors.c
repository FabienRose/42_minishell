/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:13:06 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 16:24:28 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

//Local
#include "shell/shell.h"

void util_seterror(void *shell, const char *msg)
{
	t_shell* cast_shell;
	
	if(!shell || !msg || ft_strlen(msg) == 0)
		return ;
	cast_shell = (t_shell*)shell;
	if(cast_shell->last_error)
	{
		free(cast_shell->last_error);
		cast_shell->last_error = NULL;
	}
	cast_shell->last_error = ft_strdup(msg);
}

void util_clearerror(void *shell)
{
	t_shell* cast_shell;
	
	if(!shell)
		return ;
	cast_shell = (t_shell*)shell;
	if(cast_shell->last_error)
	{
		free(cast_shell->last_error);
		cast_shell->last_error = NULL;
	}
}

void util_printerror(void *shell)
{t_shell* cast_shell;
	
	if(!shell)
		return ;
	cast_shell = (t_shell*)shell;
	if(!cast_shell->last_error)
		perror("Error: ");
	else
		printf("%s%sError: %s%s\n", FONT_RED, FONT_BOLD, cast_shell->last_error, FONT_NRM);
}
