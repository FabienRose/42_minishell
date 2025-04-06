/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:59:36 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 13:11:29 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

t_bool	tok_checkvalidity(t_token *token)
{
	char	*error_msg;

	if (!token)
		return (FALSE);
	if (token->type == TOK_NONE)
	{
		error_msg = ft_strdup("syntax error near unexpected token `");
		if (!error_msg)
			return (FALSE);
		if (!ft_strmerge(&error_msg, token->input, "'", NULL))
		{
			free(error_msg);
			return (FALSE);
		}
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd("\n", 2);
		free(error_msg);
		return (FALSE);
	}
	return (TRUE);
}

void	tok_unvalid(t_token *token, t_bool is_uniq)
{
	char	*error_msg;
	t_bool	check;

	if (!token)
		return ;
	error_msg = ft_strdup("syntax error near unexpected token `");
	if (!error_msg)
		return ;
	if (is_uniq)
		check = ft_strmerge(&error_msg, ")", "'", NULL);
	else
		check = ft_strmerge(&error_msg, token->input, "'", NULL);
	if (!check)
	{
		free(error_msg);
		return ;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	free(error_msg);
}
