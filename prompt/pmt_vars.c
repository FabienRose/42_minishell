/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:25:20 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/09 11:51:35 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_bool pmt_applyargs(t_pmt *pmt, char *value)
{
	size_t rpos;

	if(!pmt || !value)
		return (FALSE);
	rpos = 0;
	while(value[rpos])
	{
		pmt_reader_addchar(pmt->reader, value[rpos]);
		rpos++;
	}
	return (TRUE);
}

char *pmt_parseargs(t_pmt* pmt, size_t *pos)
{
	size_t end = *pos + 1;
	char *var_name;
	char *found_value;
	char *ret_value;
	
	while(pmt->prompt[end]
		&& (ft_isalnum(pmt->prompt[end])
		|| pmt->prompt[end] == '_'))
		end++;
	var_name = ft_substr(pmt->prompt, *pos + 1, end - (*pos + 1));
	if(*pos == end - 1)
	{
		free(var_name);
		return ft_strdup("$");
	}
	*pos = end - 1;
	if(!var_name)
		return (NULL);
	found_value = getenv(var_name);
	free(var_name);
	if(!found_value)
		ret_value = ft_strdup("");
	else	
		ret_value = ft_strdup(found_value);
	return (ret_value);
}

t_bool pmt_onarg(t_pmt* pmt, size_t *pos)
{
	char *var_value;
	
	var_value = pmt_parseargs(pmt, pos);
	if(!var_value)
		return (FALSE);
	if(!pmt_applyargs(pmt, var_value))
	{
		free(var_value);
		var_value = NULL;
		return (FALSE);
	}
	free(var_value);
	var_value = NULL;
	return (TRUE);
}
