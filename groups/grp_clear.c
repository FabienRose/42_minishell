/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:07:09 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 15:22:26 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

void grp_release(void *grp)
{
	grp_clear((t_grp **)&grp);
}

static void grp_clear_subs(t_grp *c_grp)
{
	if(c_grp->input_before)
	{
		free(c_grp->input_before);
		c_grp->input_before = NULL;
	}
	if(c_grp->input_after)
	{
		free(c_grp->input_after);
		c_grp->input_after = NULL;
	}
	if(c_grp->input_uniq)
	{
		free(c_grp->input_uniq);
		c_grp->input_uniq = NULL;
	}
	grp_clear(&(c_grp->grp_before));
	grp_clear(&(c_grp->grp_after));
	grp_clear(&(c_grp->grp_uniq));
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
		grp_clear_subs(c_grp);
		cmd_clear(&c_grp->cmd);
		free(c_grp);
		*grp = NULL;
	}
}
