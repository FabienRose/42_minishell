/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:54:31 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 09:06:27 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_bool pmt_iscontrole(char c)
{
	if(c == '|'
		|| c == '&'
		|| c == '>'
		|| c == '<')
		return (TRUE);
	return (FALSE);
}

t_bool pmt_isinquote(t_pmt_reader* reader)
{
	if(!reader)
		return (FALSE);
	if(reader->is_in_dq 
		|| reader->is_in_sq)
		return (TRUE);
	return (FALSE);
}