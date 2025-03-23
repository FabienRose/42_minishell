/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_tild.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:46:04 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/20 16:09:50 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret grp_addtild(t_grp* grp)
{
	char *home;
	size_t pos;
	t_promptret status;

	home = getenv("HOME");
	if(!home)
		return (PMT_SUCCESS);
	pos = 0;
	while(home[pos])
	{
		status = grp_read_addchar(grp->reader, home[pos], FALSE);
		if(status != PMT_SUCCESS)
			return (status);
		pos++;
	}
	return (PMT_SUCCESS);
}