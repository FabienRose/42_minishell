/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_io_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:50:21 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/02 15:13:58 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
#include "shell/shell.h"

static t_promptret grp_io_stdin_reset(t_grp *grp)
{
	ft_split_release(&(grp->io->input_stdin));
	grp->io->input_stdin = ft_calloc(sizeof(char *), 1);
	if(!grp->io->input_stdin)
		return (PMT_ERROR);
	return (PMT_SUCCESS);
}

static t_promptret grp_io_stdin_sigint(t_grp *grp, char **output)
{
	if(output && *output)
		free(*output);
	return (grp_io_stdin_reset(grp));
}

static t_promptret grp_io_stdin_error(char *safeword)
{
	ft_putstr_fd("minishell:  warning: here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(safeword, 2);
	ft_putstr_fd("')", 2);
	ft_putstr_fd("\n", 2);
	return (PMT_SUCCESS);
}

static t_promptret grp_io_stdin_read(t_grp *grp, char *safeword)
{
	char *output;
	size_t len;
	
	len = ft_strlen(safeword);
	output = readline("> ");
	if(!output)
		return (grp_io_stdin_error(safeword));
	if(g_onint)
		return(grp_io_stdin_sigint(grp, &output));
	while(ft_strncmp(output, safeword, len + 1) != 0)
	{
		if(!ft_arraypush_d((void ***)&(grp->io->input_stdin), output))
			return (PMT_ERROR);
		output = readline("> ");
		if(!output)
			return(grp_io_stdin_error(safeword));
		if(g_onint)
			return(grp_io_stdin_sigint(grp, &output));
	}
	if(output)
		free(output);
	return (PMT_SUCCESS);
}

t_promptret grp_io_stdin(t_grp *grp)
{
	size_t pos;
	t_promptret status;

	pos = 0;
	if(!shell_sig_switchstdin(grp->l_shell))
		return (PMT_ERROR);
	status = PMT_SUCCESS;
	while(grp->io->input_stdin_safewords[pos])
	{
		status = grp_io_stdin_reset(grp);
		if(status != PMT_SUCCESS)
			break;
		status = grp_io_stdin_read(grp, grp->io->input_stdin_safewords[pos]);
		if(status != PMT_SUCCESS)
			break;
		if(g_onint)
			break;
		pos++;
	}
	if(!shell_sig_switchdefault(grp->l_shell))
	{
		g_onint = 0;
		return (PMT_ERROR);
	}
	if(g_onint)
	{
		g_onint = 0;
		return (PMT_FAILED);
	}
	return (status);
}
