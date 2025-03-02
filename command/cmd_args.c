/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:57:40 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/02 16:27:56 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

t_bool cmd_add_arg(t_cmd *cmd, char *arg)
{
	size_t csize;

	if(!cmd || !arg)
		return (FALSE);
	if(!cmd->arguments)
	{
		cmd->arguments = ft_calloc(sizeof(char *), 1 + 1);
		if(!cmd->arguments)
			return (FALSE);
		cmd->arguments[0] = arg;
	}
	else
	{
		csize = ft_arraylen_d((void **)(cmd->arguments));
		if(!ft_realloc((void **)(&(cmd->arguments)), csize * sizeof(char *), (csize + 1 + 1) * sizeof(char *)))
			return (FALSE);
		cmd->arguments[csize] = arg;
	}
	return (TRUE);
}
