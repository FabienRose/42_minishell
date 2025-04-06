/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:26:38 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 20:26:53 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	open_append(t_grp *grp, int *file_fd)
{
	int	i;

	i = 0;
	while (grp->io->output_endfiles[i])
	{
		*file_fd = open(grp->io->output_endfiles[i],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*file_fd == -1)
			return (file_error(grp->io->output_endfiles[i], grp));
		if (grp->io->output_endfiles[i + 1])
			close(*file_fd);
		i++;
	}
	return (TRUE);
}

int	get_stdin_fd(t_grp *grp)
{
	char	*data;
	int		fd[2];
	int		i;

	data = calloc(1, 1);
	pipe(fd);
	if (fd[1] == -1)
		return (-1);
	i = 0;
	while (grp->io->input_stdin[i])
		data = ft_strjoin(data, grp->io->input_stdin[i++]);
	ft_putstr_fd(data, fd[1]);
	free(data);
	close(fd[1]);
	return (fd[0]);
}

t_bool	get_outfile_fd(t_grp *grp, char type, int *file_fd)
{
	int	i;

	i = -1;
	if (type == '>')
	{
		while (grp->io->output_files[++i])
		{
			*file_fd = open(grp->io->output_files[i],
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (*file_fd == -1)
				return (file_error(grp->io->output_files[i], grp));
			if (grp->io->output_files[i + 1])
				close(*file_fd);
		}
	}
	else if (type == 'a')
	{
		if (!open_append(grp, file_fd))
			return (FALSE);
	}
	return (TRUE);
}

int	get_infile_fd(t_grp *grp)
{
	int	i;
	int	file_fd;

	i = 0;
	while (grp->io->input_files[i])
	{
		file_fd = open(grp->io->input_files[i], O_RDONLY);
		if (file_fd == -1)
		{
			file_error(grp->io->input_files[i], grp);
			return (-1);
		}
		if (grp->io->input_files[i + 1])
			close(file_fd);
		i++;
	}
	return (file_fd);
}
