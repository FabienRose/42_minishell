/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_read_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:07:09 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 13:31:08 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups_reader.h"

void	grp_read_release(void *grp_reader)
{
	grp_read_clear((t_grp_reader **)&grp_reader);
}

void	grp_read_clear(t_grp_reader **grp_reader)
{
	t_grp_reader	*c_grp_reader;

	c_grp_reader = *grp_reader;
	if (!grp_reader || !grp_reader)
		return ;
	if (c_grp_reader->buffer)
	{
		free(c_grp_reader->buffer);
		c_grp_reader->buffer = NULL;
	}
	if (c_grp_reader)
	{
		free(c_grp_reader);
		*grp_reader = NULL;
	}
}

void	grp_read_reset(t_grp_reader *reader)
{
	ft_memset(reader->buffer, 0, reader->size);
	reader->pos = 0;
	reader->is_in_dq = FALSE;
	reader->is_in_sq = FALSE;
	reader->par_count = 0;
}
