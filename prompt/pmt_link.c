/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:05:06 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/11 16:01:53 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static void pmt_link_invtoken(t_pmt *pmt, t_token *token)
{
	char *error_msg;

	error_msg = ft_strdup("minishell: Syntax error near unexpected token '");
	if(!error_msg)
		util_seterror(pmt->l_shell, "minishell: Syntax error near unexpected token");
	else if(!ft_strmerge(&error_msg, token->input, "'", NULL))
		util_seterror(pmt->l_shell, "minishell: Syntax error near unexpected token");
	else
		util_seterror(pmt->l_shell, error_msg);
	util_printerror(pmt->l_shell);
	util_clearerror(pmt->l_shell);
	if(error_msg)
	{
		free(error_msg);
		error_msg = NULL;
	}
}


t_promtret pmt_link(t_pmt* pmt)
{
	//TODO: check token chain list e.g ( CMD ) CMD ==> error
	size_t pos;
	t_grp_parse grp_parser;
	
	pos = 0;
	while(pmt->tokens[pos])
	{
		if(pmt->tokens[pos]->type == 0)
		{
			pmt_link_invtoken(pmt, pmt->tokens[pos]);
			return PMT_FAILED;
		}
		pos++;
	}
	pmt->starting_group = grp_create();
	if(!pmt->starting_group)
		return PMT_ERROR;
	grp_parse_init(&grp_parser, pmt);
	if(!grp_parse(&grp_parser, pmt->starting_group))
		return PMT_ERROR;
	return PMT_SUCCESS;
}
