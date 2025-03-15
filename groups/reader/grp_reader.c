/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:54:27 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 12:23:27 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups_reader.h"

static t_bool grp_read_onquote(t_grp_reader* reader, char c)
{
	if(c == '\'' && !grp_isinquote(reader))
	{
		reader->is_in_sq = TRUE;
		return (TRUE);
	}
	else if(c == '\'' && grp_isinquote(reader) && reader->is_in_sq)
	{
		reader->is_in_sq = FALSE;
		return (TRUE);
	}
	else if(c == '\"' && !grp_isinquote(reader))
	{
		reader->is_in_dq = TRUE;
		return (TRUE);
	}
	else if(c == '\"' && grp_isinquote(reader) && reader->is_in_dq)
	{
		reader->is_in_dq = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool grp_read_onpar(t_grp_reader* reader, char c)
{
	if(c == '(')
		reader->par_count++;
	else if(c == ')')
	{
		if(reader->par_count == 0)
		{
			util_printerrorstr(reader->l_shell, "Unexpected token:  ')'");
			return (FALSE);
			reader->par_count--;
		}
	}
	return (TRUE);
}

t_promptret grp_read_addchar(t_grp_reader* reader, char c)
{
	grp_read_onquote(reader, c);
	if(!grp_read_onpar(reader, c))
		return (PMT_FAILED);
	if(reader->pos >= reader->size)
	{
		if(!grp_read_extendbuffer(reader))
			return (PMT_ERROR);
	}
	reader->buffer[reader->pos] = c;
	reader->pos++;
	return (PMT_SUCCESS);
}

t_bool grp_read_extendbuffer(t_grp_reader* reader)
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
	return nstr;
}