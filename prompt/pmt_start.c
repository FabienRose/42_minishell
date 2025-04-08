/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:14:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/08 12:56:31 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "shell/shell.h"

t_promptret	pmt_start(t_pmt *pmt)
{
	t_promptret	status;

	if (!pmt || !pmt->disp)
		return (PMT_ERROR);
	if (g_onint)
		printf("\n");
	g_onint = 0;
	pmt->prompt = readline(pmt->disp);
	if (pmt->prompt && ft_strlen(pmt->prompt) > 0 && pmt->prompt[0] != '\n')
	{
		add_history(pmt->prompt);
		status = pmt_checkinput(pmt);
		if (status != PMT_SUCCESS)
			return (status);
		status = pmt_parse(pmt);
		if(status != PMT_SUCCESS
			&& ((t_shell *)(pmt->l_shell))->last_return == 0)
			((t_shell *)(pmt->l_shell))->last_return = 1;
		grp_debug(pmt->start_group, 0);
		printf("Return status: %i\n", status);
		if (status != PMT_SUCCESS)
			return (status);
		return (pmt_exec(pmt));
	}
	if (!pmt->prompt)
		return (PMT_STOP);
	return (PMT_SUCCESS);
}

t_promptret	pmt_exec(t_pmt *pmt)
{
	t_promptret	status;

	status = PMT_SUCCESS;
	if (!shell_sig_switchexec(pmt->l_shell))
		return (PMT_ERROR);
	status = exec_setup(pmt->start_group);
	if (!shell_sig_switchdefault(pmt->l_shell))
		return (PMT_ERROR);
	return (status);
}
