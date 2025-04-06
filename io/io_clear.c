/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:56:08 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 13:22:20 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

static void	io_clear_str(void *str)
{
	free(str);
}

void	io_clear(t_io **io)
{
	t_io	*c_io;

	if (io && *io)
	{
		c_io = *io;
		ft_arrayfree_d((void ***)&(c_io->input_files), &io_clear_str);
		ft_arrayfree_d((void ***)&(c_io->input_stdin), &io_clear_str);
		ft_arrayfree_d((void ***)&(c_io->input_stdin_safewords), &io_clear_str);
		ft_arrayfree_d((void ***)&(c_io->output_files), &io_clear_str);
		ft_arrayfree_d((void ***)&(c_io->output_endfiles), &io_clear_str);
		free(c_io);
		*io = NULL;
	}
}
