/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:14:37 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/11 15:55:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

#include "prompt/prompt.h"

void *grp_new()
{
	return grp_create();
}
t_grp *grp_create()
{
	t_grp *n_grp;

	n_grp = ft_calloc(sizeof(t_grp), 1);
	if(!n_grp)
		return (NULL);
	if(!grp_init(n_grp))
	{
		grp_clear(&n_grp);
		return (NULL);
	}
	return n_grp;
}
t_bool grp_init(t_grp* grp)
{
	grp->input_files = ft_calloc(sizeof(t_cmd *), 1);
	if(!grp->input_files)
		return (FALSE);
	grp->output_files = ft_calloc(sizeof(t_cmd *), 1);
	if(!grp->output_files)
		return (FALSE);
	grp->output_endfiles = ft_calloc(sizeof(t_cmd *), 1);
	if(!grp->output_endfiles)
		return (FALSE);
	grp->input_stdin = ft_calloc(sizeof(t_cmd *), 1);
	if(!grp->input_stdin)
		return (FALSE);
	grp->pipe_to = NULL;
	grp->or_to = NULL;
	grp->and_to = NULL;
	grp->last_ret = PMT_NEUTRAL;
	return (TRUE);
}

t_bool grp_parse_init(t_grp_parse *parse, void *pmt)
{
	t_pmt* cpmt;
	
	if(!pmt)
		return (FALSE);
	cpmt = (t_pmt*)pmt;
	parse->l_pmt = pmt;
	parse->cmd_pos = 0;
	parse->token_pos = 0;
	parse->total_token = ft_arraylen_d((void**)(cpmt->tokens));
	return (TRUE);
}