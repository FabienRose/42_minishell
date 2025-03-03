/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:51:46 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/03 19:55:05 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	set_and_execute(t_pmt *pmt)
{
	int		i;
	t_bool	status;

	i = 0;
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
