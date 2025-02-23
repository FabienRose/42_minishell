/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:54:27 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/23 17:51:22 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_bool pmt_reader_addchar(t_pmt_reader* reader, char c)
{
	if(reader->pos >= reader->size)
	{
		if(!pmt_reader_extendbuffer(reader))
			return (FALSE);
	}
	reader->buffer[reader->pos] = c;
	reader->pos++;
	return (TRUE);
}

t_bool pmt_reader_extendbuffer(t_pmt_reader* reader)
{
	char	*nbuffer;
	size_t	i;

	nbuffer = ft_calloc(sizeof(char), reader->size + PROMT_BUFFER_SIZE + 1);
	if(!nbuffer)
		return (FALSE);
	i = 0;
	while(i < reader->size)
	{
		nbuffer[i] = reader->buffer[i];
		i++;
	}
	reader->size += PROMT_BUFFER_SIZE;
	free(reader->buffer);
	reader->buffer = nbuffer;
	return (TRUE);
}