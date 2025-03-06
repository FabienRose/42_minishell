/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:21:22 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/06 11:21:22 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	set_and_execute(t_cmd *cmd, t_pmt *pmt)
{
	t_bool	status;
	t_fd	fd;

	status = PMT_SUCCESS;
	if (cmd)
	{
		if (set_fd(cmd, &fd) == FALSE)
			return (PMT_ERROR);
		if (exec_builtins(cmd, pmt->l_shell) == PMT_SUCCESS)
			status = PMT_SUCCESS;
		else if (exec_cmd(cmd, pmt->l_shell))
			status = PMT_SUCCESS;
		else
			status = PMT_FAILED;
		if (reset_fd(&fd) == FALSE)
			return (PMT_ERROR);
	}
	if (cmd->and_to && status == PMT_SUCCESS)
		set_and_execute(cmd->and_to, pmt);
	if (cmd->or_to && status == PMT_FAILED)
		set_and_execute(cmd->or_to, pmt);
	if (cmd->pipe_to)
		set_and_execute(cmd->pipe_to, pmt);
	return (status);
}
