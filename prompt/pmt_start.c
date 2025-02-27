/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:23:39 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/27 12:26:23 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

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
	if(!pmt || ft_arraylen_d((void **)(pmt->cmds)) == 0)
		return PMT_ERROR;
	printf("Command exec: %s\n", pmt->cmds[0]->name);
	return PMT_SUCCESS;
}