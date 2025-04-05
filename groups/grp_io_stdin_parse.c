/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_io_stdin_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:13:22 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/05 17:06:40 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_promptret grp_io_stdin_parse_apply(t_grp *grp, size_t pos)
{
	t_grp *temp_grp;
	
	temp_grp = grp_create(grp->l_shell);
	if(!temp_grp)
		return (PMT_ERROR);
	temp_grp->no_varsplit = TRUE;
	grp_parseinput(temp_grp, grp->io->input_stdin[pos], TRUE);
	free(grp->io->input_stdin[pos]);
	grp->io->input_stdin[pos] = ft_strdup(temp_grp->input);
	if(!grp->io->input_stdin[pos])
	{
		grp_clear(&temp_grp);
		return (PMT_ERROR);
	}
	grp_clear(&temp_grp);
	return (PMT_SUCCESS);
}

t_promptret grp_io_stdin_parse(t_grp *grp)
{
	size_t pos;
	t_promptret status;
	
	if(!grp->io)
		return (PMT_SUCCESS);
	pos = 0;
	status = PMT_SUCCESS;
	while(grp->io->input_stdin[pos])
	{
		status = grp_io_stdin_parse_apply(grp, pos);
		if(status != PMT_SUCCESS)
			break;
		pos++;
	}
	return (status);
}