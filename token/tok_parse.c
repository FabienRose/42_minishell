/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:17 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 12:53:54 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "groups/groups.h"

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
	else if(ft_strncmp(token->input, "(", input_len) == 0)
		token->type = TOK_OPEN_PAR;
	else if(ft_strncmp(token->input, ")", input_len) == 0)
		token->type = TOK_CLOSE_PAR;
	return (TRUE);
}

t_bool tok_parse(t_token *token, void *vgrp, size_t *pos)
{
	t_grp* grp;

	grp = (t_grp*)vgrp;
	while(grp->input[*pos] 
		&& tok_iscontrole(grp->input[*pos]))
	{
		if(ft_strlen(token->input) > 0 && tok_is_par(grp->input[*pos]))
			break;
		if(!ft_strpush(&(token->input), grp->input[*pos]))
			return (FALSE);
		(*pos)++;
	}
	(*pos)--;
	tok_parse_settype(token);
	return (TRUE);
}
