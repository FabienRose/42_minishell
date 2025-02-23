/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:54:30 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/23 18:11:54 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static t_bool pmt_iscontrole(char c)
{
	if(c == '|'
		|| c == '&'
		|| c == '>'
		|| c == '<')
		return (TRUE);
	return (FALSE);
}

t_bool pmt_parse(t_pmt* pmt)
{
	size_t pos;

	(void)pmt_iscontrole;
	if(!pmt->reader)
		return (FALSE);
	pos = 0;
	while(pmt->prompt[pos])
	{
		pmt_reader_addchar(pmt->reader, pmt->prompt[pos]);
		pos++;		
	}
	return (TRUE);
}
