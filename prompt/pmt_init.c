/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:03:17 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 15:16:04 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_pmt*	pmt_new(const char* disp, void *shell)
{
	t_pmt *npmt;

	npmt = ft_calloc(sizeof(t_pmt), 1);
	if(!npmt)
		return (NULL);
	if(!pmt_init(npmt, disp, shell))
	{
		pmt_clear(&npmt);
		return (NULL);
	}
	return (npmt);
}

static t_bool pmt_init_sub(t_pmt *pmt)
{
	if(!pmt)
		return (FALSE);
	pmt->cmds = ft_calloc(sizeof(t_cmd*), 1 + 1);
	if(!pmt->cmds)
		return (FALSE);
	pmt->cmds[0] = cmd_create();
	if(!pmt->cmds[0])
		return (FALSE);
	pmt->active_cmd = pmt->cmds[0];
	pmt->tokens = ft_calloc(sizeof(t_token*), 1 + 1);
	if(!pmt->tokens)
		return (FALSE);
	pmt->last_token = NULL;
	return (TRUE);
}

t_bool	pmt_init(t_pmt* pmt, const char* disp, void *shell)
{
	if(!pmt || !disp || ft_strlen(disp) == 0)
	{
		util_seterror(shell, "Missing or invalid arg on pmt_init");
		return (FALSE);
	}
	pmt->disp = ft_strdup(disp);
	if(!pmt->disp)
		return (FALSE);
	pmt->reader = pmt_reader_new();
	if(!pmt->reader)
		return (FALSE);
	if(!pmt_init_sub(pmt))
		return (FALSE);
	pmt->l_shell = shell;
	pmt->prompt = NULL;
	return (TRUE);
}

t_pmt_reader* pmt_reader_new()
{
	t_pmt_reader *nreader;

	nreader = ft_calloc(sizeof(t_pmt_reader), 1);
	if(!nreader)
		return (NULL);
	if(!pmt_reader_init(nreader))
	{
		pmt_reader_clear(&nreader);
		return (NULL);
	}
	return (nreader);
}

t_bool pmt_reader_init(t_pmt_reader *reader)
{
	if(!reader)
		return (FALSE);
	reader->buffer = ft_calloc(sizeof(char), PROMT_BUFFER_SIZE + 1);
	if(!reader->buffer)
		return (FALSE);
	reader->pos = 0;
	reader->size = PROMT_BUFFER_SIZE;
	reader->is_in_sq = FALSE;
	reader->is_in_dq = FALSE;
	return(TRUE);
}