/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:17:17 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/10 16:17:17 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	chk_onquote(t_chk *chk, char c)
{
	if (!chk->in_sq && !chk->in_dq)
	{
		if (c == '\'')
			chk->in_sq = TRUE;
		else if (c == '\"')
			chk->in_dq = TRUE;
	}
	else if (c == '\'' && chk->in_sq)
		chk->in_sq = FALSE;
	else if (c == '\"' && chk->in_dq)
		chk->in_dq = FALSE;
}

static t_promptret	chk_onpar(t_chk *chk, char c)
{
	if (chk->in_sq || chk->in_dq)
		return (PMT_SUCCESS);
	if (c == '(')
		chk->par_count++;
	else if (c == ')')
	{
		if (chk->par_count <= 0)
		{
			chk_unexpteced_ctoken(chk, c);
			return (PMT_FAILED);
		}
		chk->par_count--;
	}
	return (PMT_SUCCESS);
}

t_promptret	chk_onchar(t_chk *chk, char c)
{
	t_promptret	status;

	status = PMT_SUCCESS;
	if (c == '\'' || c == '\"')
		chk_onquote(chk, c);
	if (c == '(' || c == ')')
		status = chk_onpar(chk, c);
	return (status);
}
