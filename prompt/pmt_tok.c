/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:22:17 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 10:31:04 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

t_bool pmt_addtok(t_pmt* pmt, size_t *pos)
{
	t_token* ntoken;

	ntoken = tok_create();
	if(!ntoken)
		return (FALSE);
	if(!ft_arraypush_d((void***)&(pmt->tokens), ntoken))
		return (FALSE);
	if(!tok_parse(ntoken, pmt, pos))
		return (FALSE);
	return (TRUE);
}