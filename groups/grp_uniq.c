/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_uniq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:08:56 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/20 14:39:17 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"


static t_promptret grp_check_uniq_loop(t_grp* grp)
{
	size_t pos;
	t_promptret status;

	pos = 0;
	while(grp->input[pos])
	{
		status = grp_read_addchar_at(grp->reader, grp->input[pos], 1);
		if(status != PMT_SUCCESS)
			return (status);
		pos++;
	}
	return (PMT_SUCCESS);
}
t_promptret grp_check_uniq(t_grp* grp)
{
	t_promptret status;

	grp_read_reset(grp->reader);
	status = grp_check_uniq_loop(grp);
	if(status != PMT_SUCCESS)
		return (status);
	if(grp->reader->pos != 0)
	{
		grp->input_uniq = grp_read_extract(grp->reader);
		if(!grp->input_uniq)
			return (PMT_ERROR);
	}
	if(grp->input_uniq)
	{
		grp->grp_uniq = grp_create(grp->l_shell);
		if(!grp->grp_uniq)
			return (PMT_ERROR);
		status = grp_set_input(grp->grp_uniq, grp->input_uniq, FALSE);
	}
	return (status);
}
