/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_io_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:50:21 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/05 17:36:41 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "groups.h"
#include "shell/shell.h"

static t_promptret grp_io_stdin_read(char *safeword, int *fds)
{
	char *output;
	size_t len;
	
	len = ft_strlen(safeword);
	output = readline("> ");
	while(output && ft_strncmp(output, safeword, len + 1) != 0)
	{
		write(fds[1], output, ft_strlen(output));
		write(fds[1], "\n", 1);
		free(output);
		output = readline("> ");
	}
	if(!output)
		return (grp_io_stdin_error(safeword));
	if(output)
		free(output);
	return (PMT_STOP);
}

static t_promptret grp_io_stdin_apply(t_grp *grp, int *fds)
{
	char *output;
	
	output = ft_gnl(fds[0]);
	while(output)
	{
		if(!ft_arraypush_d((void ***)&(grp->io->input_stdin), output))
		{
			free(output);
			return (PMT_FAILED);
		}
		output = ft_gnl(fds[0]);
	}
	close(fds[0]);
	return (PMT_SUCCESS);
}

static t_promptret grp_io_stdin_start(t_grp *grp, char *safeword)
{
	int			pid;
	int			fds[2];
	t_promptret	status;

	if(pipe(fds) != 0)
		return (PMT_ERROR);
	pid = fork();
	if(pid == -1)
		return (PMT_ERROR);
	if(pid == 0)
	{
		shell_sig_switchkill(grp->l_shell);
		status = grp_io_stdin_read(safeword, fds);
		if(status != PMT_SUCCESS)
			return (status);
		return (PMT_STOP);
	}
	else
		waitpid(pid, NULL, 0);
	close(fds[1]);
	if(g_onint == 1)
	{
		printf("^C\n");
		return (PMT_FAILED);
	}
	return (grp_io_stdin_apply(grp, fds));
}

static t_promptret grp_io_stdin_end(t_grp *grp, t_promptret status)
{
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
	if(status != PMT_SUCCESS)
		return (status);
	return (grp_io_stdin_parse(grp));
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
		status = grp_io_stdin_start(grp, grp->io->input_stdin_safewords[pos]);
		if(status != PMT_SUCCESS)
			break;
		if(g_onint)
			break;
		pos++;
	}
	return (grp_io_stdin_end(grp, status));
}
