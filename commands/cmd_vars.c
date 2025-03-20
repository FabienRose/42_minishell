/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 08:38:20 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/20 10:56:35 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static t_bool cmd_check_setvar_clear(t_cmd *cmd)
{
	char *buffer;

	if(cmd->name)
		free(cmd->name);
	if(ft_arraylen_d((void **)(cmd->args)) == 0)
		cmd->name = ft_strdup("");
	else
		cmd->name = ft_arraypopfront_d((void ***)&(cmd->args));
	if(!cmd->name)
		return (FALSE);
	if(ft_arraylen_d((void **)(cmd->full)) != 0)
	{
		buffer = ft_arraypopfront_d((void ***)&(cmd->full));
		if(!buffer)
			return (FALSE);
		free(buffer);
	}
	return (TRUE);
}

t_bool cmd_check_setvar(t_cmd *cmd)
{
	char *found;
	size_t pos;
	size_t len;
	
	if(!cmd)
		return (FALSE);
	if(!cmd->name || ft_strlen(cmd->name) == 0)
		return (TRUE);
	found = ft_strfrchr(cmd->name, '=');
	if(!found)
		return (TRUE);
	cmd->var_isset = TRUE;
	pos = (long int)found - (long int)(cmd->name);
	len = ft_strlen(cmd->name);
	cmd->var_name = ft_substr(cmd->name, 0, pos);
	if(!cmd->var_name)
		return (FALSE);
	cmd->var_data = ft_substr(cmd->name, pos + 1, len - (pos + 1));
	if(!cmd->var_data)
		return (FALSE);
	return (cmd_check_setvar_clear(cmd));
}
