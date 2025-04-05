/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_vars_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:47:16 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/05 17:09:35 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
#include "shell/shell.h"

static size_t grp_var_process_getend(char *value, t_grp_varreader *reader)
{
	size_t pos;

	pos = reader->pos;
	while(value[pos])
	{
		if(value[pos] == '\'')
			reader->has_sq = TRUE;
		if(value[pos] == '\"')
			reader->has_dq = TRUE;
		if(ft_isspace(value[pos]))
			break;
		pos++;
	}
	return (pos - 1);
}


static t_bool grp_var_process_apply(char **value, t_grp_varreader *reader)
{
	char active_q;

	active_q = '\"';
	if(reader->has_dq)
		active_q = '\'';
	if(!ft_strinsert(value, reader->pos, active_q))
	{
		free(*value);
		return (FALSE);
	}
	if(!ft_strinsert(value, reader->end + 2, active_q))
	{
		free(*value);
		return (FALSE);
	}
	return (TRUE);
}

char *grp_var_process(t_grp* grp, char *value)
{
	char *output;
	t_grp_varreader reader;
	
	output = ft_strdup(value);
	if(!output)
		return (NULL);
	if(grp->reader->is_in_dq || grp->no_varsplit)
		return (output);
	reader.pos = 0;
	reader.end = 0;
	while(output[reader.pos])
	{
		reader.has_sq = FALSE;
		reader.has_dq = FALSE;
		if(!ft_isspace(output[reader.pos]))
		{
			reader.end = grp_var_process_getend(output, &reader);
			if(!grp_var_process_apply(&output, &reader))
				return (NULL);
			reader.pos = reader.end + 2;
		}
		reader.pos++;
	}
	return (output);
}

t_promptret grp_apply_lastresult(t_grp* grp)
{
	char *last_str;
	t_shell *shell;
	size_t pos;
	t_promptret status;

	shell = (t_shell *)(grp->l_shell);
	last_str = ft_itoa(shell->last_return);
	if(!last_str)
		return (PMT_ERROR);
	pos = 0;
	status = PMT_SUCCESS;
	while(last_str[pos])
	{
		status = grp_read_addchar(grp->reader, last_str[pos], FALSE);
		if(status != PMT_SUCCESS)
			break;
		pos++;
	}
	free(last_str);
	return (status);
}
