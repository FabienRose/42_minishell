/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:57:43 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/09 17:43:12 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "shell/shell.h"

t_promtret pmt_start(t_pmt* pmt)
{	
	t_promtret ret;

	if(!pmt || !pmt->disp)
		return PMT_ERROR;
	pmt->prompt = readline(pmt->disp);
	if(pmt->prompt && ft_strlen(pmt->prompt) > 0  && pmt->prompt[0] != '\n')
	{
		add_history(pmt->prompt);
		if(!pmt_parse(pmt))
			return (PMT_ERROR);
		ret = pmt_link(pmt);
		if(ret != PMT_SUCCESS)
			return (ret);
		return (pmt_exec(pmt));
	}
	if(!pmt->prompt)
		return (PMT_STOP);
	return (PMT_SUCCESS);
}

t_promtret pmt_exec(t_pmt* pmt)
{
	t_promtret status;
	
	pmt_print(pmt);
	if(!pmt || ft_arraylen_d((void **)(pmt->cmds)) == 0)
		return PMT_ERROR;
	status = set_and_execute(pmt->cmds[0], pmt);
	return (status);
}
