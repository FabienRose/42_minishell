/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:57:43 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/22 15:05:29 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "shell/shell.h"

t_promptret pmt_start(t_pmt* pmt)
{	
	t_promptret status;
	
	if(!pmt || !pmt->disp)
		return PMT_ERROR;
	pmt->prompt = readline(pmt->disp);
	if(pmt->prompt && ft_strlen(pmt->prompt) > 0  && pmt->prompt[0] != '\n')
	{
		add_history(pmt->prompt);
		status = pmt_parse(pmt);
		grp_debug(pmt->start_group, 0);
		if(status != PMT_SUCCESS)
			return (status);
		return (pmt_exec(pmt));
	}
	if(!pmt->prompt)
		return (PMT_STOP);
	return (PMT_SUCCESS);
}

t_promptret pmt_exec(t_pmt* pmt)
{
	t_promptret status;
	
	pmt_print(pmt);
	(void)status;
	return PMT_SUCCESS;
	// if(!pmt || ft_arraylen_d((void **)(pmt->cmds)) == 0)
	// 	return PMT_ERROR;
	// status = set_and_execute(pmt->cmds[0], pmt);
	// return (status);
}
