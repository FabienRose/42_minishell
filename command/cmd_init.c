/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:28:22 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/02 17:38:32 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	*cmd_new()
{
	return (void *)(cmd_create());
}

t_cmd	*cmd_create()
{
	t_cmd *ncmd;

	ncmd = ft_calloc(sizeof(t_cmd), 1);
	if(!ncmd)
		return (NULL);
	if(!cmd_init(ncmd))
	{
		cmd_clear(&ncmd);
		return (NULL);
	}
	return ncmd;
}

t_bool	cmd_init(t_cmd* cmd)
{
	cmd->name = NULL;
	cmd->arguments = ft_calloc(sizeof(char *), 1);
	if(!cmd->arguments)
		return (FALSE);
	cmd->full_cmd = ft_calloc(sizeof(char *), 1);;
	if(!cmd->full_cmd)
		return (FALSE);
	cmd->input_files = ft_calloc(sizeof(t_cmd *), 1);
	if(!cmd->input_files)
		return (FALSE);
	cmd->output_files = ft_calloc(sizeof(t_cmd *), 1);
	if(!cmd->output_files)
		return (FALSE);
	cmd->output_endfiles = ft_calloc(sizeof(t_cmd *), 1);
	if(!cmd->output_endfiles)
		return (FALSE);
	cmd->input_stdin = ft_calloc(sizeof(t_cmd *), 1);
	if(!cmd->input_stdin)
		return (FALSE);
	cmd->pipe_to = NULL;
	cmd->or_to = NULL;
	cmd->and_to = NULL;
	return (TRUE);
}
