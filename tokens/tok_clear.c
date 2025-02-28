/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:32:40 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 13:55:18 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"


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
void	tok_release(void *token)
{
	tok_clear((t_token **)(&token));
}