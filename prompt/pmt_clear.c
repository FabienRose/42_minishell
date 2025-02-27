/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:03:23 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/27 11:33:19 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	pmt_clear_cmds(t_pmt *pmt)
{
	size_t pos;

	if(!pmt->cmds)
		return ;
	pos = 0;
	while(pmt->cmds[pos])
	{
		cmd_clear(&(pmt->cmds[pos]));
		pos++;
	}
	free(pmt->cmds);
	pmt->cmds = NULL;
}

void	pmt_clear(t_pmt **pmt)
{
	t_pmt *cpmt = *pmt;
	if(cpmt)
	{
		if(cpmt->disp)
		{
			free(cpmt->disp);
			cpmt->disp = NULL;
		}
		if(cpmt->prompt)
		{
			free(cpmt->prompt);
			cpmt->prompt = NULL;
		}
		pmt_reader_clear(&(cpmt->reader));
		pmt_clear_cmds(cpmt);
		free(cpmt);
	}
	*pmt = NULL;
}

void	pmt_reader_clear(t_pmt_reader **reader)
{
	t_pmt_reader *creader;

	creader = *reader;
	if(!reader || !creader)
		return ;
	if(creader->buffer)
	{
		free(creader->buffer);
		creader->buffer = NULL;
	}
	if(creader)
	{
		free(creader);
		*reader = NULL;
	}
}