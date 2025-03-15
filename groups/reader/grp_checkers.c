/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:54:31 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 10:43:03 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups_reader.h"

t_bool grp_isinquote(t_grp_reader* reader)
{
	if(!reader)
		return (FALSE);
	if(reader->is_in_dq 
		|| reader->is_in_sq)
		return (TRUE);
	return (FALSE);
}