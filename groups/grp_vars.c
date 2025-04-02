/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:16:35 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/01 16:27:04 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret grp_parseinput_apply(t_grp* grp, char *name)
{
	char *env_value;
	t_promptret status;
	size_t pos;
	
	if(ft_strlen(name) == 0)
		return (grp_read_addchar(grp->reader, '$', FALSE));
	if(ft_strlen(name) == 1 && name[0] == '?')
		return grp_apply_lastresult(grp);
	env_value = getenv(name);
	if(!env_value)
		return (PMT_SUCCESS);
	pos = 0;
	env_value = grp_var_process(grp, env_value);
	if(!env_value)
		return PMT_ERROR;
	status = PMT_SUCCESS;
	while(env_value[pos])
	{
		status = grp_read_addchar(grp->reader, env_value[pos], FALSE);
		if(status != PMT_SUCCESS)
			break;
		pos++;
	}
	free(env_value);
	return (status);
}

t_promptret grp_parseinput_getvalue(t_grp* grp, const char *input, size_t *pos)
{
	char *var_name;
	size_t len;
	t_promptret status;
	
	var_name = ft_calloc(sizeof(char), 1);
	if(!var_name)
		return (PMT_ERROR);
	len = 0;
	while(input[*pos])
	{
		if(!ft_isalnum(input[*pos]) && input[*pos] != '_' && input[*pos] != '?')
			break;
		if(!ft_realloc((void **)&(var_name), len, len + 2))
		{
			free(var_name);
			return (PMT_ERROR);
		}
		var_name[len++] = input[*pos];
		(*pos)++;
	}
	status = grp_parseinput_apply(grp, var_name);
	free(var_name);
	return (status);
}

t_promptret grp_parseinput_loop(t_grp* grp, const char *input)
{
	size_t pos;
	t_promptret status;
	
	pos = 0;
	while(input[pos])
	{
		if(input[pos] == '$' && !grp->reader->is_in_sq)
		{
			pos++;
			status = grp_parseinput_getvalue(grp, input, &pos);
			if(!input[pos])
				break;
		}
		if(input[pos] == '~' && !grp->reader->is_in_sq)
			status = grp_addtild(grp);
		else
			status = grp_read_addchar(grp->reader, input[pos], FALSE);
		if(status != PMT_SUCCESS)
			return (status);
		pos++;
	}
	return (PMT_SUCCESS);
}

t_promptret grp_parseinput(t_grp* grp, const char *input, t_bool is_first)
{
	t_promptret status;
	
	if(!is_first)
	{
		grp->input = ft_strdup(input);
		if(!grp->input)
			return (PMT_ERROR);
		return (PMT_SUCCESS);
	}
	status = grp_parseinput_loop(grp, input);
	if(status != PMT_SUCCESS)
		return (status);
	grp->input = grp_read_extract(grp->reader);
	if(!grp->input)
		return (PMT_ERROR);
	return (PMT_SUCCESS);
}
