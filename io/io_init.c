/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:41:02 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/30 15:47:37 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

t_io *io_create()
{
	t_io *n_io;

	n_io = ft_calloc(sizeof(t_io), 1);
	if(!n_io)
		return (NULL);
	if(!io_init(n_io))
	{
		io_clear(&n_io);
		return (NULL);
	}
	return (n_io);
}

t_bool io_init(t_io* io)
{
	io->input_files = ft_calloc(sizeof(char *), 1);
	if(!io->input_files)
		return (FALSE);
	io->input_stdin = ft_calloc(sizeof(char *), 1);
	if(!io->input_stdin)
		return (FALSE);
	io->input_stdin_safewords = ft_calloc(sizeof(char *), 1);
	if(!io->input_stdin_safewords)
		return (FALSE);
	io->output_files = ft_calloc(sizeof(char *), 1);
	if(!io->output_files)
		return (FALSE);
	io->output_endfiles = ft_calloc(sizeof(char *), 1);
	if(!io->output_endfiles)
		return (FALSE);
	return (TRUE);
}