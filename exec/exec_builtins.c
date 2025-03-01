/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:14:21 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/01 13:17:13 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_bool	env_builtins(t_pmt *pmt)
{
	if (ft_strncmp(pmt->cmds[0]->name, "export", 7) == 0)
	{
		export(pmt->l_shell, pmt->cmds[0]->arguments);
		return (TRUE);
	}
	else if (ft_strncmp(pmt->cmds[0]->name, "unset", 6) == 0)
	{
		unset(pmt->l_shell, pmt->cmds[0]->arguments);
		return (TRUE);
	}
	else if (ft_strncmp(pmt->cmds[0]->name, "env", 4) == 0)
	{
		print_env(pmt->l_shell, pmt->cmds[0]->arguments);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	cd_builtins(t_pmt *pmt)
{
	if (ft_strncmp(pmt->cmds[0]->name, "cd", 3) == 0)
	{
		if (!change_directory(pmt->l_shell, pmt->cmds[0]->arguments))
			return (FALSE);
		shell_update_loc(pmt->l_shell);
		return (TRUE);
	}
	else if (ft_strncmp(pmt->cmds[0]->name, "pwd", 4) == 0)
	{
		if (!pwd(pmt->cmds[0]->arguments))
			return (FALSE);
		return (TRUE);
	}
	else if (ft_strncmp(pmt->cmds[0]->name, "echo", 5) == 0)
	{
		echo(pmt->cmds[0]->arguments);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	exec_builtins(t_pmt *pmt)
{
	if (env_builtins(pmt))
		return (PMT_SUCCESS);
	else if (cd_builtins(pmt))
		return (PMT_SUCCESS);
	return (PMT_FAILED);
}
