/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:49:34 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 10:08:29 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void pmt_print(t_pmt* pmt)
{
	size_t pos;
	printf("\n====================== COMMANDS ======================\n\n");
	pos = 0;
	while(pmt->cmds[pos])
	{
		printf("--- CMD (%li) : %p ---\n", pos, pmt->cmds[pos]);
		cmd_print(pmt->cmds[pos++]);
	}
	printf("\n\n====================== TOKENS ======================\n\n");
	pos = 0;
	while(pmt->tokens[pos])
	{
		printf("--- TOKEN (%li) : %p ---\n", pos, pmt->tokens[pos]);
		tok_print(pmt->tokens[pos++]);
	}
}