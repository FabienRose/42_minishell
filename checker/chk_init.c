/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:08:06 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/26 17:42:11 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*chk_new(void)
{
	return (chk_create());
}

t_chk	*chk_create(void)
{
	t_chk	*nchk;

	nchk = ft_calloc(sizeof(t_chk), 1);
	if (!nchk)
		return (NULL);
	if (!chk_init(nchk))
	{
		chk_clear(&nchk);
		return (NULL);
	}
	return (nchk);
}

t_bool	chk_init(t_chk *chk)
{
	if (!chk)
		return (FALSE);
	chk->in_dq = FALSE;
	chk->in_sq = FALSE;
	chk->par_count = 0;
	chk->last_msg = NULL;
	return (TRUE);
}
