/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:59:36 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 13:05:26 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

t_bool tok_checkvalidity(t_token* token)
{
	char *error_msg;

	if(token->type == TOK_NONE)
	{
		error_msg = ft_strdup("Unexpected token: '");
		if(!error_msg)
			return (FALSE);
		if(!ft_strmerge(&error_msg, token->input, "'", NULL))
		{
			free(error_msg);
			return (FALSE);
		}
		util_printerrorstr(token->l_shell, error_msg);
		free(error_msg);
		return (FALSE);
	}
	return (TRUE);
}