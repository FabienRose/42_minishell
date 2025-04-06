/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:29 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/28 12:46:58 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static t_bool cmd_add_full(t_cmd* cmd, const char *data)
{
	size_t len;
	len = ft_arraylen_d((void **)(cmd->full));
	if(!ft_realloc_da((void ***)&(cmd->full), len, len + 2))
		return (FALSE);
	cmd->full[len] = ft_strdup(data);
	if(!cmd->full[len])
		return (FALSE);
	return (TRUE);
}

t_bool cmd_add(t_cmd* cmd, char *data)
{
	size_t len;

	if(!cmd)
		return (FALSE);
	if(!cmd->name)
	{
		cmd->name = data;
		return (cmd_add_full(cmd, data));
	}
	len = ft_arraylen_d((void **)(cmd->args));
	if(!ft_realloc_da((void ***)&(cmd->args), len, len + 2))
	{
		free(data);
		return (FALSE);
	}
	cmd->args[len] = data;
	return (cmd_add_full(cmd, data));
}
