/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:28:02 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/27 14:28:02 by fmixtur          ###   ########.ch       */
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