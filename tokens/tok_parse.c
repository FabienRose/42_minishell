/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:17 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/02 17:34:54 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "prompt/prompt.h"

static t_bool tok_parse_settype(t_token* token)
{
	size_t input_len;

	input_len = ft_strlen(token->input) + 1;
	if(ft_strncmp(token->input, "<", input_len) == 0)
		token->type = TOK_REDIR_IN;
	else if(ft_strncmp(token->input, ">", input_len) == 0)
		token->type = TOK_REDIR_OUT;
	else if(ft_strncmp(token->input, "<<", input_len) == 0)
		token->type = TOK_READ_STDIN;
	else if(ft_strncmp(token->input, ">>", input_len) == 0)
		token->type = TOK_REDIR_OUTEND;
	else if(ft_strncmp(token->input, "||", input_len) == 0)
		token->type = TOK_OR;
	else if(ft_strncmp(token->input, "&&", input_len) == 0)
		token->type = TOK_AND;
	else if(ft_strncmp(token->input, "|", input_len) == 0)
		token->type = TOK_PIPE;
	return (TRUE);
}

t_bool tok_parse(t_token *token, void *vpmt, size_t *pos)
{
	t_pmt* pmt;

	pmt = (t_pmt*)vpmt;
	while(pmt->prompt[*pos] 
		&& tok_iscontrole(pmt->prompt[*pos]))
	{
		if(!ft_strpush(&(token->input), pmt->prompt[*pos]))
			return (FALSE);
		(*pos)++;
	}
	(*pos)--;
	tok_parse_settype(token);
	return (TRUE);
}