/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_uniq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:08:56 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/30 11:48:52 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"


static t_promptret grp_check_uniq_loop(t_grp* grp)
{
	size_t pos;
	t_promptret status;
	t_bool set;
	t_bool set_started;

	pos = 0;
	set_started = FALSE;
	while(grp->input_after_uniq[pos])
	{
		set = FALSE;
		status = grp_read_addchar_at(grp->reader, grp->input_after_uniq[pos], 1, &set);
		if(status != PMT_SUCCESS)
			return (status);
		if(set)
		{
			set_started = TRUE;
			if(!ft_strpopat(&(grp->input_after_uniq), pos))
				return (PMT_ERROR);
		}
		else
			pos++;
		if(set == FALSE && set_started == TRUE)
			return (PMT_SUCCESS);
	}
	return (PMT_SUCCESS);
}
t_promptret grp_check_uniq(t_grp* grp)
{
	t_promptret status;

	grp_read_reset(grp->reader);
	grp->input_after_uniq = ft_strdup(grp->input);
	if(!grp->input_after_uniq)
		return (PMT_ERROR);
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
		grp->grp_uniq->is_uniq = TRUE;
		status = grp_set_input(grp->grp_uniq, grp->input_uniq, FALSE);
	}
	return (status);
}
