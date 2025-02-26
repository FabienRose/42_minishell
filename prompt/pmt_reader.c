/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:54:27 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 09:22:15 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static t_bool pmt_reader_onquote(t_pmt_reader* reader, char c)
{
	if(c == '\'' && !pmt_isinquote(reader))
	{
		reader->is_in_sq = TRUE;
		return (TRUE);
	}
	else if(c == '\'' && pmt_isinquote(reader) && reader->is_in_sq)
	{
		reader->is_in_sq = FALSE;
		return (TRUE);
	}
	else if(c == '\"' && !pmt_isinquote(reader))
	{
		reader->is_in_dq = TRUE;
		return (TRUE);
	}
	else if(c == '\"' && pmt_isinquote(reader) && reader->is_in_dq)
	{
		reader->is_in_dq = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

t_bool pmt_reader_addchar(t_pmt_reader* reader, char c)
{
	if(pmt_reader_onquote(reader, c))
		return (TRUE);
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

char *pmt_reader_extract(t_pmt_reader *reader)
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
	return nstr;
}