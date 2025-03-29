/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:00:50 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/29 21:20:41 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_promptret	redirect_fd_input(t_grp *grp)
{
	int	file_fd;

	if (grp->io->input_files[0] || grp->io->input_stdin[0])
	{
		if (grp->io->input_files[0])
			file_fd = get_infile_fd(grp);
		else
			file_fd = get_stdin_fd(grp);
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

t_promptret	redirect_fd_output(t_grp *grp)
{
	int	file_fd;

	file_fd = -1;
	if (grp->io->output_files[0] || grp->io->output_endfiles[0])
	{
		if (grp->io->output_files[0])
			get_outfile_fd(grp, '>', &file_fd);
		else
			get_outfile_fd(grp, 'a', &file_fd);
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
