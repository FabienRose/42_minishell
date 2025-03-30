/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_io_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:50:21 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/30 19:32:31 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_promptret grp_io_stdin_reset(t_grp *grp)
{
	ft_split_release(&(grp->io->input_stdin));
	grp->io->input_stdin = ft_calloc(sizeof(char *), 1);
	if(!grp->io->input_stdin)
		return (PMT_ERROR);
	return (PMT_SUCCESS);
}
static t_promptret grp_io_stdin_read(t_grp *grp, char *safeword)
{
	char *output;
	size_t len;
	
	len = ft_strlen(safeword);
	output = readline("> ");
	printf("HELLO WORLD\n");
	if(!output)
		return (PMT_SUCCESS);
	while(ft_strncmp(output, safeword, len + 1) != 0)
	{
		ft_arraypush_d((void ***)&(grp->io->input_stdin), output);
		output = readline("> ");
		printf("HELLO WORLD\n");
		if(!output)
			break;
	}
	if(output)
		free(output);
	return (PMT_SUCCESS);
}

t_promptret grp_io_stdin(t_grp *grp)
{
	size_t pos;
	t_promptret status;

	pos = 0;
	while(grp->io->input_stdin_safewords[pos])
	{
		status = grp_io_stdin_reset(grp);
		if(status != PMT_SUCCESS)
			return (status);
		status = grp_io_stdin_read(grp, grp->io->input_stdin_safewords[pos]);
		if(status != PMT_SUCCESS)
			return (status);
		pos++;
	}
	return (PMT_SUCCESS);
}