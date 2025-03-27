/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:32:40 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/27 14:19:49 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

void	tok_release(void *token)
{
	tok_clear((t_token **)(&token));
}

void	tok_clear(t_token **token)
{
	t_token *ctoken;

	ctoken = *token;
	if(ctoken)
	{
		if(ctoken->input)
		{
			free(ctoken->input);
			ctoken->input = NULL;
		}
		
		free(ctoken);
		*token = NULL;
	}
}