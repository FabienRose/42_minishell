/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:30:18 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 18:11:34 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret grp_getcmd_applychar(t_grp *grp, size_t pos)
{
	char *extract;
	
	if((ft_isspace(grp->input_after_io[pos]) && !grp_isinquote(grp->reader)) 
		|| grp->input_after_io[pos] == 0)
	{
		if(ft_strlen(grp->reader->buffer) == 0)
			return (PMT_SUCCESS);
		extract = grp_read_extract(grp->reader);
		if(!extract)
			return (PMT_ERROR);
		if(!cmd_add(grp->cmd, extract))
			return (PMT_ERROR);
		return (PMT_SUCCESS);
	}
	return (grp_read_addchar(grp->reader, grp->input_after_io[pos], TRUE));
}

t_promptret grp_getcmd(t_grp *grp)
{
	size_t pos;
	t_promptret status;
	
	grp->cmd = cmd_create(grp->l_shell);
	if(!grp->cmd)
		return (PMT_ERROR);
	grp_read_reset(grp->reader);
	pos = 0;
	while(grp->input_after_io[pos])
	{
		status = grp_getcmd_applychar(grp, pos);
		if(status != PMT_SUCCESS)
			return (status);
		pos++;
	}
	status = grp_getcmd_applychar(grp, pos);
	if(status != PMT_SUCCESS)
		return (status);
	return (PMT_SUCCESS);
}
