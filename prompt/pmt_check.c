/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:51:43 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/26 17:55:18 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_promptret pmt_checkinput(t_pmt *pmt)
{
	size_t pos;
	t_promptret status;

	pos = 0;
	status = PMT_SUCCESS;
	while(pmt->prompt[pos])
	{
		status = chk_onchar(pmt->checker, pmt->prompt[pos]);
		if(status != PMT_SUCCESS)
			break;
		pos++;
	}
	if(status != PMT_SUCCESS)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(pmt->checker->last_msg, 2);
		ft_putstr_fd("\n", 2);
	}
	return (status);
}