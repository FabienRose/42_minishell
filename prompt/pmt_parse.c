/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:54:30 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/10 13:53:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_promptret	pmt_parse(t_pmt *pmt)
{
	if (ft_strlen(pmt->prompt) == 0)
		return (PMT_SUCCESS);
	return (grp_set_input(pmt->start_group, pmt->prompt, TRUE));
}
