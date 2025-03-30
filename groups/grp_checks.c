/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:36:40 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/30 14:57:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

static t_promptret grp_check_printerror(char *error)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd("\n", 2);
	return (PMT_FAILED);
}

static t_promptret grp_check_gettoken(t_grp *grp, size_t pos)
{
	char *token_str;

	token_str = ft_calloc(sizeof(char), 1);
	if(!token_str)
		return (PMT_ERROR);
	while(grp->input_after_io[pos]
		&& !tok_iscontrole(grp->input_after_io[pos])
		&& !ft_isspace(grp->input_after_io[pos]))
	{
		if(!ft_strpush(&token_str, grp->input_after_io[pos]))
		{
			free(token_str);
			return (PMT_ERROR);
		}
		pos++;	
	}
	grp_check_printerror(token_str);
	free(token_str);
	return (PMT_FAILED);	
}

t_promptret grp_check_residue(t_grp *grp)
{
	int count_open;
	int count_close;
	size_t pos;

	count_open = 0;
	count_close = 0;
	pos = 0;
	while(grp->input_after_io[pos])
	{
		if(grp->input_after_io[pos] == '(')
			count_open++;
		else if(grp->input_after_io[pos] == ')')
			count_close++;
		else if(!ft_isspace(grp->input_after_io[pos]))
			return (grp_check_gettoken(grp, pos));
		if(count_open > 1)
			return (grp_check_printerror("("));
		if(count_close > 1)
			return (grp_check_printerror(")"));
		pos++;
	}
	return (PMT_SUCCESS);
}
