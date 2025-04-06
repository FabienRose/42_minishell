/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_io_stdin_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:47:41 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 14:50:24 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"

t_promptret	grp_io_stdin_reset(t_grp *grp)
{
	ft_split_release(&(grp->io->input_stdin));
	grp->io->input_stdin = ft_calloc(sizeof(char *), 1);
	if (!grp->io->input_stdin)
		return (PMT_ERROR);
	return (PMT_SUCCESS);
}

t_promptret	grp_io_stdin_sigint(t_grp *grp, char **output)
{
	if (output && *output)
		free(*output);
	return (grp_io_stdin_reset(grp));
}

t_promptret	grp_io_stdin_error(char *safeword)
{
	ft_putstr_fd("minishell:  warning: here-document delimited ", 2);
	ft_putstr_fd("by end-of-file (wanted `", 2);
	ft_putstr_fd(safeword, 2);
	ft_putstr_fd("')", 2);
	ft_putstr_fd("\n", 2);
	return (PMT_STOP);
}
