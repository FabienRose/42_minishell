/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:39 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 13:15:29 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

t_bool	tok_iscontrole(char c)
{
	if (c == '|'
		|| c == '&'
		|| c == '>'
		|| c == '<'
		|| c == '('
		|| c == ')')
		return (TRUE);
	return (FALSE);
}

t_bool	tok_isio(char c)
{
	if (c == '>'
		|| c == '<')
		return (TRUE);
	return (FALSE);
}

t_bool	tok_issubcontrole(char c)
{
	if (c == '|'
		|| c == '&')
		return (TRUE);
	return (FALSE);
}

t_bool	tok_is_par(char c)
{
	if (c == '('
		|| c == ')')
		return (TRUE);
	return (FALSE);
}

t_bool	tok_is_redir(t_token *token)
{
	if (!token)
		return (FALSE);
	if (token->type == TOK_READ_STDIN
		|| token->type == TOK_REDIR_IN
		|| token->type == TOK_REDIR_OUT
		|| token->type == TOK_REDIR_OUTEND)
		return (TRUE);
	return (FALSE);
}
