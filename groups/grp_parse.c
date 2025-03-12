/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:08:00 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/12 10:40:31 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

#include "prompt/prompt.h"

static t_bool grp_parse_onnewsub(t_grp_parse *parse, t_grp* grp)
{
	t_grp *ngrp;
	t_pmt *pmt;

	pmt = parse->l_pmt;
	ngrp = grp_create();
	if(!ngrp)
		return (FALSE);
	if(!ft_arraypush_d((void***)&(grp->sub_grps), ngrp))
	{
		grp_clear(&ngrp);
		return (FALSE);
	}
	pmt->tokens[parse->token_pos - 1]->assigned_group = ngrp;
	return grp_parse(parse, ngrp);
}



t_bool grp_parse(t_grp_parse *parse, t_grp* grp)
{
	t_pmt *pmt;

	pmt = parse->l_pmt;
	while(parse->token_pos < parse->total_token
		&& pmt->tokens[parse->token_pos]->type != TOK_CLOSE_PAR)
	{
		if(pmt->tokens[parse->token_pos]->type == TOK_OPEN_PAR)
		{
			parse->token_pos++;
			if(!grp_parse_onnewsub(parse, grp))
				return  (FALSE);
		}
		else
		{
			if(!ft_arraypush_d((void ***)&(grp->tokens), pmt->tokens[parse->token_pos]))
				return (FALSE);
		}
		parse->token_pos++;
	}
	if(!grp_regroup(grp, 0))
		return (FALSE);
	return (TRUE);
}
