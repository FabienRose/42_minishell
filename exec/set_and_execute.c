/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:13:30 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/25 12:15:20 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_promptret	set_and_execute(t_grp *grp)
{
	t_promptret	status;
	//t_fd		fd;
	status = PMT_SUCCESS;
	if (grp->cmd)
	{
		/*if (set_fd(grp->cmd, &fd) == FALSE) //Check if error of just failed
			return (PMT_FAILED	);*/
		if (exec_builtins(grp->cmd, grp->l_shell) == PMT_SUCCESS)
			status = PMT_SUCCESS;
		else if (exec_cmd(grp->cmd, grp->l_shell))
			status = PMT_SUCCESS;
		else
			status = PMT_FAILED;
		/*if (reset_fd(&fd) == FALSE)
			return (PMT_ERROR);*/
	}
	/*if (grp->and_to && status == PMT_SUCCESS)
		set_and_execute(grp->and_to, pmt);
	if (grp->or_to && status == PMT_FAILED)
		set_and_execute(grp->or_to, pmt);
	if (grp->pipe_to)
		set_and_execute(grp->pipe_to, pmt);*/
	return (status);
}
