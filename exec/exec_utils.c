/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:42:25 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/27 18:42:25 by fmixtur          ###   ########.ch       */
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
/*
t_bool	set_fd(t_cmd *cmd, t_fd *fd)
{
	fd->saved_stdin = dup(STDIN_FILENO);
	fd->saved_stdout = dup(STDOUT_FILENO);
	if (!redirect_fd_output(cmd) && cmd->pipe_to)
	{
		pipe(fd->pipe_fd);
		dup2(fd->pipe_fd[1], STDOUT_FILENO);
		if (fd->pipe_fd[1] == -1)
			return (FALSE);
		close(fd->pipe_fd[1]);
		cmd->pipe_to->previous_pipe = fd->pipe_fd[0];
	}
	if (!redirect_fd_input(cmd))
		return (FALSE);
	if (cmd->previous_pipe)
	{
		dup2(cmd->previous_pipe, STDIN_FILENO);
		if (cmd->previous_pipe == -1)
			return (FALSE);
		close(cmd->previous_pipe);
	}
	return (TRUE);
}

int	get_file_fd(t_cmd *cmd, char type)
{
	int	file_fd;
	int	i;

	i = 0;
	while (type == 'o' && cmd->output_files[i])
	{
		file_fd = open(cmd->output_files[i]->name,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		i++;
	}
	while (type == 'o' && cmd->output_endfiles[i])
	{
		file_fd = open(cmd->output_endfiles[i]->name,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		i++;
	}
	while (type == 'i' && cmd->input_files[i])
	{
		file_fd = open(cmd->input_files[i]->name, O_RDONLY);
		if (file_fd == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(cmd->input_files[i]->name, 2);
			perror(": ");
			return (-1);
		}
		i++;
	}
	return (file_fd);
}

*/

int	get_outfile_fd(t_grp *grp, char type)
{
	int	file_fd;
	int	i;

	i = 0;
	while (grp->io->output_files[i] || grp->io->output_endfiles[i])
	{
		if (type == '>')
			file_fd = open(grp->io->output_files[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (type == 'a')
			file_fd = open(grp->io->output_endfiles[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (file_fd == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			if (type == '>')
				ft_putstr_fd(grp->io->output_files[i], 2);
			else if (type == 'a')
				ft_putstr_fd(grp->io->output_endfiles[i], 2);
			perror(": ");
			return (-1);
		}
		i++;
	}
	return (file_fd);
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

t_bool	redirect_fd_input(t_grp *grp)
{
	int	file_fd;

	if (grp->io->input_files[0])
	{
		file_fd = get_infile_fd(grp);
		if (file_fd == -1)
			return (FALSE);
		if (dup2(file_fd, STDIN_FILENO) == -1)
		{
			close(file_fd);
			return (FALSE);
		}
		close(file_fd);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	redirect_fd_output(t_grp *grp)
{
	int	file_fd;

	if (grp->io->output_files[0] || grp->io->output_endfiles[0])
	{
		if (grp->io->output_files[0])
			file_fd = get_outfile_fd(grp, '>');
		else
			file_fd = get_outfile_fd(grp, 'a');
		if (file_fd == -1)
			return (FALSE);
		if (dup2(file_fd, STDOUT_FILENO) == -1)
		{
			close(file_fd);
			return (FALSE);
		}
		close(file_fd);
		return (TRUE);
	}
	return (FALSE);
}
