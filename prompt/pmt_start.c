/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:23:39 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/22 18:02:31 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_promtret pmt_start(t_pmt* pmt)
{
	char *input;
	
	if(!pmt || !pmt->disp)
		return PMT_ERROR;
	input = readline(pmt->disp);
	printf("HELLO\n");
	if(input && ft_strlen(input) > 0  && input[0] != '\n')
		add_history(input);
	if(input)
	{
		free(input);
		input = NULL;
	}
	else
		return PMT_STOP;
	return PMT_SUCCESS;
}