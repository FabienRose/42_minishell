/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:08:06 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/26 17:42:05 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	chk_release(void *chk)
{
	return (chk_clear((t_chk **)&chk));
}

void	chk_clear(t_chk **chk)
{
	t_chk	*cchk;

	cchk = *chk;
	if (cchk)
	{
		if(cchk->last_msg)
		{
			free(cchk->last_msg);
			cchk->last_msg = NULL;
		}
		free(cchk);
		*chk = NULL;
	}
}
