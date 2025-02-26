/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:54:30 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 16:59:04 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static t_bool pmt_parse_applyctrl(t_pmt* pmt, char *extract)
{
	if(!pmt->active_cmd)
		return (FALSE);
	if(!pmt->active_cmd->name)
		pmt->active_cmd->name = extract;
	else
	{
		if(!cmd_add_arg(pmt->active_cmd, extract))
			return (FALSE);
	}
	return (TRUE);
}
static t_bool pmt_parse_onctrl(t_pmt* pmt, size_t pos)
{	
	char *extract;
	
	extract = pmt_reader_extract(pmt->reader);
	if(!extract)
		return (FALSE);
	if(ft_strlen(extract) == 0)
	{
		free(extract);
		extract = NULL;
	}
	if(extract && !pmt_parse_applyctrl(pmt, extract))
	{
		free(extract);
		return (FALSE);
	}
	if(pmt_iscontrole(pmt->prompt[pos]) && !pmt_newcmd(pmt))
		return (FALSE);
	return (TRUE);
}

static t_bool pmt_parse_check(t_pmt *pmt, size_t pos)
{
	if((!pmt->prompt[pos] || pmt_iscontrole(pmt->prompt[pos])
		|| ft_isspace(pmt->prompt[pos])) 
		&& !pmt_isinquote(pmt->reader))
	{
		if(!pmt_parse_onctrl(pmt, pos))
			return (FALSE);
	}
	else
	{
		if(!pmt_reader_addchar(pmt->reader, pmt->prompt[pos]))
			return (FALSE);
	}
	return (TRUE);
}

t_bool pmt_parse(t_pmt* pmt)
{
	size_t pos;

	if(!pmt->reader)
		return (FALSE);
	pos = 0;
	while(pmt->prompt[pos])
	{
		if(!pmt_parse_check(pmt, pos))
			return (FALSE);
		pos++;		
	}
	if(!pmt_parse_check(pmt, pos))
		return (FALSE);
	pmt_print(pmt);
	return (TRUE);
}
