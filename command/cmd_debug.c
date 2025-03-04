/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:10:22 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/03 16:14:42 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static void cmd_print_link(const char *head, t_cmd *linked)
{
	if(linked)
		printf("%s: %s (%p)\n", head, linked->name, linked);
	else
	printf("%s: None\n", head);
}

static void cmd_print_linkarr(const char *head, t_cmd **linked)
{
	size_t pos;

	if(ft_arraylen_d((void **)linked) == 0)
		return ;
	printf("- %s -\n", head);
	pos = 0;
	while(linked[pos])
	{
		printf("\t%li: %s (%p)\n", pos, linked[pos]->name, linked[pos]);
		pos++;
	}
}

void cmd_print_sub(t_cmd* cmd)
{
	cmd_print_link("Pipe to", cmd->pipe_to);
	cmd_print_link("Or to", cmd->or_to);
	cmd_print_link("And to", cmd->and_to);
	cmd_print_linkarr("Input files", cmd->input_files);
	cmd_print_linkarr("Output files", cmd->output_files);
	cmd_print_linkarr("Output End files", cmd->output_endfiles);
	cmd_print_linkarr("Input from stdin", cmd->input_stdin);
}

void cmd_print(t_cmd* cmd)
{
	size_t i;
	
	if(!cmd)
	{
		printf("Debug: no cmd passed");
		return ;
	}
	if(cmd->name)
		printf ("Name: %s\n", cmd->name);
	i = 0;
	if(!cmd->arguments)
		return ;
	while (cmd->arguments[i])
	{
		printf("Arg %lu: %s\n", i, cmd->arguments[i]);
		i++;
	}
	cmd_print_sub(cmd);
	printf("\n\n");
}
