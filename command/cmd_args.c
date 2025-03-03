/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:57:40 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/03 16:29:34 by kgauthie         ###   ########.fr       */
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

char **cmd_get_fullarray(t_cmd *cmd)
{
	size_t len;
	size_t pos;

	if(!cmd)
		return (NULL);
	if(cmd->full_args)
		return cmd->full_args;
	len = ft_arraylen_d(cmd->arguments);
	cmd->full_args = ft_calloc(sizeof(char *), len  + 1 + 1);
	if(!cmd->full_args)
		return (NULL);
	cmd->full_args[0] = cmd->name;
	pos = 1;
	while(pos <= len)
	{
		cmd->full_args[pos] = cmd->arguments[pos - 1];
		pos++;
	}
	return (cmd->full_args);
}