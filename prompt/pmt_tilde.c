/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:55:03 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/09 12:09:04 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_bool pmt_ontilde(t_pmt* pmt)
{
	char *home_dir;
	size_t pos;
	
	if(!pmt)
		return (FALSE);
	home_dir = getenv("HOME");
	if(!home_dir)
	{
		if(!pmt_reader_addchar(pmt->reader, '~'))
			return (FALSE);
		return (TRUE);
	}
	pos = 0;
	while(home_dir[pos])
	{
		if(!pmt_reader_addchar(pmt->reader, home_dir[pos]))
			return (FALSE);
		pos++;
	}
	return (TRUE);
}