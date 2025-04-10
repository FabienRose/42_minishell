/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:27:27 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/10 16:27:27 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "shell/shell.h"

static void	pmt_start_gv(t_pmt *pmt)
{
	if (g_onint == 1)
		printf("\n");
	if (g_onint == 2)
		((t_shell *)(pmt->l_shell))->last_return = 131;
	g_onint = 0;
}

t_promptret	pmt_start(t_pmt *pmt)
{
	t_promptret	status;

	if (!pmt || !pmt->disp)
		return (PMT_ERROR);
	pmt_start_gv(pmt);
	pmt->prompt = readline(pmt->disp);
	if (pmt->prompt && ft_strlen(pmt->prompt) > 0 && pmt->prompt[0] != '\n')
	{
		add_history(pmt->prompt);
		status = pmt_checkinput(pmt);
		if (status != PMT_SUCCESS)
			return (status);
		status = pmt_parse(pmt);
		if (status != PMT_SUCCESS
			&& ((t_shell *)(pmt->l_shell))->last_return == 0)
			((t_shell *)(pmt->l_shell))->last_return = 1;
		if (status != PMT_SUCCESS)
			return (status);
		return (pmt_exec(pmt));
	}
	if (!pmt->prompt)
		printf("exit\n");
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
