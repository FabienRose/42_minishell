/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:54:27 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 15:12:34 by kgauthie         ###   ########.fr       */
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
	if(grp_isinquote(reader))
		return (TRUE);
	if(c == '(')
		reader->par_count++;
	else if(c == ')')
	{
		if(reader->par_count == 0)
		{
			util_printerrorstr(reader->l_shell, "Unexpected token:  ')'");
			return (FALSE);
		}
		reader->par_count--;
	}
	return (TRUE);
}

t_promptret grp_read_addchar(t_grp_reader* reader, char c, t_bool no_quotes)
{
	if(grp_read_onquote(reader, c) && no_quotes)
		return (PMT_SUCCESS);
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

t_promptret grp_read_addchar_at(t_grp_reader* reader, char c, size_t min_par)
{
	t_bool is_active;
	
	is_active = reader->par_count >= min_par;
	grp_read_onquote(reader, c);
	if(!grp_read_onpar(reader, c))
		return (PMT_FAILED);
	if(reader->par_count < min_par || !is_active)
		return (PMT_SUCCESS);
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
