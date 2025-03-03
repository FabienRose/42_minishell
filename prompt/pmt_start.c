/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:15:09 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/03 14:18:46 by fmixtur          ###   ########.ch       */
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
	int		i;
	t_bool	status;

	i = 0;
	//TODO: A refaire
	// pmt_print(pmt);
	if(!pmt || ft_arraylen_d((void **)(pmt->cmds)) == 0)
		return PMT_ERROR;
	while (pmt->cmds[i])
	{
		if (exec_builtins(pmt->cmds[i], pmt->l_shell) == PMT_SUCCESS)
			status = PMT_SUCCESS;
		else if (exec_cmd(pmt->cmds[i], pmt->l_shell))
			status = PMT_SUCCESS;
		else
			status = PMT_FAILED;

		i++;
	}
	return (status);
}
