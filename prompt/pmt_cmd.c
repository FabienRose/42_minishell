/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:05:54 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 10:16:40 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_bool pmt_newcmd(t_pmt* pmt)
{
	size_t cmd_len;
	
	if(!pmt || !pmt->cmds || !pmt->active_cmd)
		return (FALSE);
	cmd_len = ft_darraylen((void **)(pmt->cmds));
	if(!ft_realloc((void **)(&(pmt->cmds)), cmd_len * sizeof(t_cmd *), (cmd_len + 1 + 1) * sizeof(t_cmd *)))
		return (FALSE);
	
}