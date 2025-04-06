/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:44:39 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:38:22 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_promptret	shell_nextprompt(t_shell *shell)
{
	t_pmt		*current_pmt;
	char		*head;
	t_promptret	retvalue;

	head = shell_gethead(shell);
	if (!head)
	{
		util_seterror(shell, "Cannot get header");
		return (PMT_ERROR);
	}
	current_pmt = pmt_new(head, shell);
	free(head);
	if (!current_pmt)
		return (PMT_ERROR);
	retvalue = pmt_start(current_pmt);
	pmt_clear(&current_pmt);
	return (retvalue);
}

t_bool	shell_start(t_shell *shell)
{
	t_promptret	ret;

	if (!shell_update_loc(shell))
		return (FALSE);
	ret = shell_nextprompt(shell);
	while (ret != PMT_ERROR && ret != PMT_STOP)
	{
		ret = shell_nextprompt(shell);
	}
	if (ret == PMT_ERROR)
		return (FALSE);
	return (TRUE);
}
