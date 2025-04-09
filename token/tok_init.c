/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:32:35 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 13:13:37 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

t_token	*tok_create(void *shell)
{
	t_token	*ntoken;

	ntoken = ft_calloc(sizeof(t_token), 1);
	if (!ntoken)
		return (NULL);
	if (!tok_init(ntoken, shell))
	{
		tok_clear(&ntoken);
		return (NULL);
	}
	return (ntoken);
}

t_bool	tok_init(t_token *token, void *shell)
{
	if (!token)
		return (FALSE);
	token->input = ft_calloc(sizeof(char), 1);
	if (!token->input)
		return (FALSE);
	token->type = TOK_NONE;
	token->l_shell = shell;
	return (TRUE);
}
