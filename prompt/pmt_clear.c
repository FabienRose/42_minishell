/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:03:23 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/22 09:16:48 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	pmt_clear(t_pmt **pmt)
{
	t_pmt *cpmt = *pmt;
	if(cpmt->disp)
	{
		free(cpmt->disp);
		cpmt->disp = NULL;
	}
	if(cpmt)
	{
		free(cpmt);
		*pmt = NULL;
	}
}