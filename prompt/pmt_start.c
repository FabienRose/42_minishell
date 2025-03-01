/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:49:36 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/01 12:51:10 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "shell/shell.h"

t_promtret pmt_start(t_pmt* pmt)
{	
	if(!pmt || !pmt->disp)
		return PMT_ERROR;
	pmt->prompt = readline(pmt->disp);
	if(pmt->prompt && ft_strlen(pmt->prompt) > 0  && pmt->prompt[0] != '\n')
	{
		add_history(pmt->prompt);
		if(!pmt_parse(pmt))
			return (PMT_ERROR);
		return (pmt_exec(pmt));
	}
	if(!pmt->prompt)
		return (PMT_STOP);
	return (PMT_SUCCESS);
}

t_promtret pmt_exec(t_pmt* pmt)
{
	//TODO: A refaire
	if(!pmt || ft_arraylen_d((void **)(pmt->cmds)) == 0)
		return PMT_ERROR;
	if (!exec_builtins(pmt))
		return (PMT_SUCCESS);
	return (PMT_FAILED);
}
