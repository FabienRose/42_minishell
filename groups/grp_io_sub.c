/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_io_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:22:16 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/27 16:23:10 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_bool grp_getio_merge(t_grp *grp)
{
	char *local;

	if(ft_strlen(grp->reader->buffer) == 0)
		return (TRUE);
	local = grp_read_extract(grp->reader);
	if(!local)
		return (FALSE);
	if(!ft_strmerge(&(grp->input_after_io), local, NULL, NULL))
	{
		free(local);
		return (FALSE);
	}
	free(local);
	return (TRUE);
}

t_promptret grp_getio_applytoio(t_grp *grp, t_token *token)
{
	char ***target_arr;
	char *extract;
	
	if(!grp->io)
		grp->io = io_create();
	if(!grp->io)
		return (PMT_ERROR);
	if(token->type == TOK_REDIR_IN)
		target_arr = &(grp->io->input_files);
	else if(token->type == TOK_READ_STDIN)
		target_arr = &(grp->io->input_stdin);
	else if(token->type == TOK_REDIR_OUT)
		target_arr = &(grp->io->output_files);
	else if(token->type == TOK_REDIR_OUTEND)
		target_arr = &(grp->io->output_endfiles);
	extract = grp_read_extract(grp->reader);
	if(!extract)
		return (PMT_ERROR);
	if(!ft_arraypush_d((void ***)target_arr, extract))
	{
		free(extract);
		return (PMT_ERROR);
	}
	return (PMT_SUCCESS);
}