/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:03:48 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/27 15:20:35 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_promptret chk_finalcheck(t_chk* chk)
{
	if(chk->par_count > 0)
	{
		chk_custom_message(chk, "Unclosed parenthesis");
		return (PMT_FAILED);
	}
	if(chk->in_dq || chk->in_sq)
	{
		chk_custom_message(chk, "Unclosed quotes");
		return (PMT_FAILED);
	}
	return (PMT_SUCCESS);
}