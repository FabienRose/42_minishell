/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:45 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/26 17:55:13 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void chk_unexpteced_ctoken(t_chk *chk, char c)
{
	if(chk->last_msg)
	{
		free(chk->last_msg);
		chk->last_msg = NULL;
	}
	chk->last_msg = ft_strdup("Syntax error near unexpected token ` '");
	if(!chk->last_msg)
		return ;
	chk->last_msg[36] = c;
}