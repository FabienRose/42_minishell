/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:32:18 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 15:07:44 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	get_infile_order(t_grp *grp, int *file_fd, int is_stdin)
{
	if (is_stdin)
	{
		if (grp->io->input_files[0])
			*file_fd = get_infile_fd(grp);
		if (grp->io->input_stdin[0])
			*file_fd = get_stdin_fd(grp);
	}
	else
	{
		if (grp->io->input_stdin[0])
			*file_fd = get_stdin_fd(grp);
		if (grp->io->input_files[0])
			*file_fd = get_infile_fd(grp);
	}
}

t_promptret	redirect_fd_input(t_grp *grp)
{
	int		file_fd;
	int		is_stdin;
	char	*last_in;

	last_in = ft_strrchr(grp->input, '<');
	if (last_in && last_in > grp->input && *(last_in - 1) == '<')
		is_stdin = 1;
	else
		is_stdin = 0;
	if (grp->io->input_files[0] || grp->io->input_stdin[0])
	{
		get_infile_order(grp, &file_fd, is_stdin);
		if (file_fd == -1)
			return (PMT_FAILED);
		if (dup2(file_fd, STDIN_FILENO) == -1)
		{
			close(file_fd);
			return (PMT_ERROR);
		}
		close(file_fd);
		return (PMT_SUCCESS);
	}
	return (PMT_FAILED);
}

void	get_outfile_order(t_grp *grp, int *file_fd, int is_append)
{
	if (is_append)
	{
		if (grp->io->output_files[0])
			get_outfile_fd(grp, '>', file_fd);
		if (grp->io->output_endfiles[0])
			get_outfile_fd(grp, 'a', file_fd);
	}
	else
	{
		if (grp->io->output_endfiles[0])
			get_outfile_fd(grp, 'a', file_fd);
		if (grp->io->output_files[0])
			get_outfile_fd(grp, '>', file_fd);
	}
}

t_promptret	redirect_fd_output(t_grp *grp)
{
	int		file_fd;
	char	*last_out;
	int		is_append;

	file_fd = -1;
	last_out = ft_strrchr(grp->input, '>');
	if (last_out && last_out > grp->input && *(last_out - 1) == '>')
		is_append = 1;
	else
		is_append = 0;
	if (grp->io->output_files[0] || grp->io->output_endfiles[0])
	{
		get_outfile_order(grp, &file_fd, is_append);
		if (file_fd == -1)
			return (PMT_ERROR);
		if (dup2(file_fd, STDOUT_FILENO) == -1)
		{
			close(file_fd);
			return (PMT_ERROR);
		}
		close(file_fd);
		return (PMT_SUCCESS);
	}
	return (PMT_FAILED);
}
