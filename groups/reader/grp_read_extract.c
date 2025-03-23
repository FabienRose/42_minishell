/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_read_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:48:50 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/17 17:48:57 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups_reader.h"

char *grp_read_extract(t_grp_reader *reader)
{
	char *nstr;

	if(!reader)
		return (NULL);
	nstr = ft_calloc(sizeof(char), ft_strlen(reader->buffer) + 1);
	if(!nstr)
		return (NULL);
	ft_strcpy(nstr, reader->buffer);
	ft_memset(reader->buffer, 0, reader->size);
	reader->pos = 0;
	reader->is_in_dq = FALSE;
	reader->is_in_sq = FALSE;
	reader->par_count = 0;
	return nstr;
}