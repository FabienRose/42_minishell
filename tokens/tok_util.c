/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:39 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/06 08:20:04 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_bool tok_iscontrole(char c)
{
	if(c == '|'
		|| c == '&'
		|| c == '>'
		|| c == '<')
		return (TRUE);
	return (FALSE);
}

t_bool tok_is_redir(t_token *token)
{
	if(!token)
		return (FALSE);
	if(token->type == TOK_READ_STDIN
		|| token->type == TOK_REDIR_IN
		|| token->type == TOK_REDIR_OUT
		|| token->type == TOK_REDIR_IN)
		return (TRUE);
	return (FALSE);
}