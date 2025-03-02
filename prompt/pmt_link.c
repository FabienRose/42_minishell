/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:05:06 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/02 17:40:30 by kgauthie         ###   ########.fr       */
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

static t_cmd *pmt_link_apply_sub(t_pmt *pmt, t_cmd* active_cmd, size_t pos)
{
	if(pmt->tokens[pos]->type == TOK_PIPE)
	{
		active_cmd->pipe_to = pmt->cmds[pos + 1];
		return pmt->cmds[pos + 1];
	}
	else if(pmt->tokens[pos]->type == TOK_OR)
	{
		active_cmd->or_to = pmt->cmds[pos + 1];
		return pmt->cmds[pos + 1];
	}
	else if(pmt->tokens[pos]->type == TOK_AND)
	{
		active_cmd->and_to = pmt->cmds[pos + 1];
		return pmt->cmds[pos + 1];
	}
	return (active_cmd);
}

static t_cmd *pmt_link_apply(t_pmt *pmt, t_cmd* active_cmd, size_t pos)
{
	if(pmt->tokens[pos]->type == TOK_REDIR_IN
		&& !ft_arraypush_d((void ***)&(active_cmd->input_files), pmt->cmds[pos + 1]))
			return (NULL);
	else if(pmt->tokens[pos]->type == TOK_REDIR_OUT
		&& !ft_arraypush_d((void ***)&(active_cmd->output_files), pmt->cmds[pos + 1]))
			return (NULL);
	else if(pmt->tokens[pos]->type == TOK_REDIR_OUTEND
		&& !ft_arraypush_d((void ***)&(active_cmd->output_endfiles), pmt->cmds[pos + 1]))
			return (NULL);
	else if(pmt->tokens[pos]->type == TOK_READ_STDIN
		&& !ft_arraypush_d((void ***)&(active_cmd->input_stdin), pmt->cmds[pos + 1]))
			return (NULL);
	return (pmt_link_apply_sub(pmt, active_cmd, pos));
}

t_promtret pmt_link(t_pmt* pmt)
{
	size_t pos;
	t_cmd *current_cmd;
	
	pos = 0;
	current_cmd = pmt->cmds[0];
	while(pmt->tokens[pos])
	{
		if(pmt->tokens[pos]->type == 0)
		{
			pmt_link_invtoken(pmt, pmt->tokens[pos]);
			return PMT_FAILED;
		}
		current_cmd = pmt_link_apply(pmt, current_cmd, pos);
		if(!current_cmd)
			return (PMT_ERROR);
		pos++;
	}
	return PMT_SUCCESS;
}
