/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:07:09 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 13:07:21 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

void grp_release(void *grp)
{
	grp_clear((t_grp **)&grp);
}
void grp_clear(t_grp **grp)
{
	t_grp *c_grp;

	c_grp = *grp;
	if(c_grp)
	{
		grp_read_clear(&(c_grp->reader));
		tok_clear(&(c_grp->token));
		if(c_grp->input)
		{
			free(c_grp->input);
			c_grp->input = NULL;
		}
		free(c_grp);
		*grp = NULL;
	}
}