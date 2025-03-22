/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_vars_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:47:16 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/22 15:57:38 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
#include "shell/shell.h"

t_promptret grp_apply_lastresult(t_grp* grp)
{
	char *last_str;
	t_shell *shell;
	size_t pos;
	t_promptret status;

	shell = (t_shell *)(grp->l_shell);
	last_str = ft_itoa(shell->last_return);
	if(!last_str)
		return (PMT_ERROR);
	pos = 0;
	status = PMT_SUCCESS;
	while(last_str[pos])
	{
		status = grp_read_addchar(grp->reader, last_str[pos], FALSE);
		if(status != PMT_SUCCESS)
			break;
		pos++;
	}
	free(last_str);
	return (status);
}
