/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_read_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:07:05 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 13:29:38 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups_reader.h"

t_grp_reader	*grp_read_create(void *shell)
{
	t_grp_reader	*ngrp_reader;

	ngrp_reader = ft_calloc(sizeof(t_grp_reader), 1);
	if (!ngrp_reader)
		return (NULL);
	if (!grp_read_init(ngrp_reader, shell))
	{
		grp_read_clear(&ngrp_reader);
		return (NULL);
	}
	return (ngrp_reader);
}

t_bool	grp_read_init(t_grp_reader *grp_reader, void *shell)
{
	if (!grp_reader)
		return (FALSE);
	grp_reader->buffer = ft_calloc(sizeof(char), PROMT_BUFFER_SIZE + 1);
	if (!grp_reader->buffer)
		return (FALSE);
	grp_reader->pos = 0;
	grp_reader->size = PROMT_BUFFER_SIZE;
	grp_reader->is_in_sq = FALSE;
	grp_reader->is_in_dq = FALSE;
	grp_reader->par_count = 0;
	grp_reader->l_shell = shell;
	return (TRUE);
}
