/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:06:24 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/04 19:06:24 by fmixtur          ###   ########.ch       */
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
	cmd->previous_pipe = 0;
	cmd->arguments = ft_calloc(sizeof(char *), 1);
	if(!cmd->arguments)
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
	cmd->full_args = NULL;
	cmd->pipe_to = NULL;
	cmd->or_to = NULL;
	cmd->and_to = NULL;
	return (TRUE);
}
