/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:14:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/05 13:59:25 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "shell/shell.h"

t_promptret pmt_start(t_pmt* pmt)
{	
	t_promptret status;
	
	if(!pmt || !pmt->disp)
		return PMT_ERROR;
	if(g_onint)
		printf("\n");
	g_onint = 0;
	pmt->prompt = readline(pmt->disp);
	if(pmt->prompt && ft_strlen(pmt->prompt) > 0  && pmt->prompt[0] != '\n')
	{
		add_history(pmt->prompt);
		status = pmt_checkinput(pmt);
		if(status != PMT_SUCCESS)
			return (status);
		status = pmt_parse(pmt);
		printf("Return status: %i\n", status);
		if(status != PMT_SUCCESS)
			return (status);
		grp_debug(pmt->start_group, 0);
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
	status = PMT_SUCCESS;
	// if(!pmt || ft_arraylen_d((void **)(pmt->cmds)) == 0)
	// 	return PMT_ERROR;
	if(!shell_sig_switchexec(pmt->l_shell))
		return(PMT_ERROR);
	status = set_and_execute(pmt->start_group);
	if(!shell_sig_switchdefault(pmt->l_shell))
		return(PMT_ERROR);
	return (status);
}
