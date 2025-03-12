/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:54:30 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/12 18:11:12 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"


t_bool pmt_parse(t_pmt* pmt)
{
	size_t pos;

	if(!pmt->reader)
		return (FALSE);
	pos = 0;
	while(pmt->prompt[pos])
	{
		pos++;		
	}
	return (TRUE);
}
