/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:32:35 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/12 16:40:04 by kgauthie         ###   ########.fr       */
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
	token->prev = NULL;
	token->next = NULL;
	token->prev_grp = NULL;
	token->next_grp = NULL;
	token->prev_tok = NULL;
	token->next_tok = NULL;
	token->assigned_group = NULL;
	token->lastid = 0;
	return (TRUE);	
}
