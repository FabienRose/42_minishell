/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:08:00 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/11 16:28:31 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

#include "prompt/prompt.h"

t_bool grp_parse(t_grp_parse *parse, t_grp* grp)
{
	t_pmt *pmt;

	(void)grp;
	pmt = parse->l_pmt;
	while(parse->token_pos < parse->total_token
		&& pmt->tokens[parse->token_pos]->type != TOK_CLOSE_PAR)
	{
		printf("Token: %p\n", pmt->tokens[parse->token_pos]);
		parse->token_pos++;
	}
	return (TRUE);
}