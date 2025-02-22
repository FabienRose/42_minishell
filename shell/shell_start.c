/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:44:39 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/22 09:59:06 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_promtret shell_nextprompt(t_shell* shell)
{
	t_pmt	*current_pmt;
	char	*head;
	
	head = shell_gethead(shell);
	if(!head)
	{
		util_seterror(shell, "Cannot get header");
		return (PMT_ERROR);
	}
	current_pmt = pmt_new(head, shell);
	free(head);
	if(!current_pmt)
		return (PMT_ERROR);
	printf("%s\n", current_pmt->disp);
	pmt_clear(&current_pmt);
	return (PMT_FAILED);
}

t_bool shell_start(t_shell* shell)
{
	t_promtret	ret;
	
	if(!shell_update_loc(shell))
		return (FALSE);
	ret = shell_nextprompt(shell);
	if(ret == PMT_ERROR)
		return (FALSE);
	return (TRUE);
}
