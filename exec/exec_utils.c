/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:02:10 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/29 19:02:10 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_bool	reset_fd(t_fd *fd)
{
	dup2(fd->saved_stdin, STDIN_FILENO);
	dup2(fd->saved_stdout, STDOUT_FILENO);
	close(fd->saved_stdin);
	close(fd->saved_stdout);
	return (TRUE);
}

t_bool	file_error(char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	perror(": ");
	return (FALSE);
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
				return (file_error(grp->io->output_files[i]));
		}
	}
	else if (type == 'a')
	{
		while (grp->io->output_endfiles[++i])
		{
			*file_fd = open(grp->io->output_endfiles[i],
					O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (*file_fd == -1)
				return (file_error(grp->io->output_endfiles[i]));
		}
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
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(grp->io->input_files[i], 2);
			perror(": ");
			return (-1);
		}
		i++;
	}
	return (file_fd);
}

/*t_promptret	redirect_fd_input(t_grp *grp)
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
}*/
