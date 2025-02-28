/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:05:54 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 10:15:20 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_bool pmt_newcmd(t_pmt* pmt)
{
	t_cmd *cmd;

	if(!pmt || !pmt->cmds || !pmt->active_cmd)
		return (FALSE);
	cmd = cmd_create();
	if(!cmd)
		return (FALSE);
	if(!ft_arraypush_d((void ***)(&pmt->cmds), cmd))
	{
		cmd_clear(&cmd);
		return (FALSE);
	}
	pmt->active_cmd = cmd;	
	return (TRUE);
}