/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:42:42 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/28 12:40:55 by fmixtur          ###   ########.ch       */
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
		if(ft_strchr(extract, '*'))
			return (grp_expand_wildcard(grp, extract));
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
	if(!cmd_check_setvar(grp->cmd))
		return  (PMT_ERROR);
	return (PMT_SUCCESS);
}
