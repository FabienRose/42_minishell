/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:32:35 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 10:30:58 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*tok_create()
{
	t_token* ntoken;

	ntoken = ft_calloc(sizeof(t_token), 1);
	if(!ntoken)
		return (NULL);
	if(!tok_init(ntoken))
	{
		tok_clear(&ntoken);
		return (NULL);
	}
	return (ntoken);
}
void	*tok_new()
{
	return tok_create();
}
t_bool	tok_init(t_token* token)
{
	if(!token)
		return (FALSE);
	token->input = ft_calloc(sizeof(char), 1);
	if(!token->input)
		return (FALSE);
	token->type = TOK_NONE;
	return (TRUE);	
}