/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:03:17 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 13:45:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_pmt*	pmt_new(const char* disp)
{
	t_pmt *npmt;

	npmt = ft_calloc(sizeof(t_pmt), 1);
	if(!npmt)
		return (NULL);
	if(!pmt_init(npmt, disp))
	{
		pmt_clear(&npmt);
		return (NULL);
	}
	return (npmt);
}
t_bool	pmt_init(t_pmt* pmt, const char* disp)
{
	if(!pmt || !disp || ft_strlen(disp) == 0)
		return (FALSE);
	pmt->disp = ft_strdup(disp);
	if(!pmt->disp)
		return (FALSE);
	return (TRUE);
}