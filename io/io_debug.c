/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:01:32 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 16:09:48 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

static void io_print_arr(char **arr, char *name, char *tabs, int tab_count)
{
	size_t pos;
	
	printf("%i %s    %s: %li\n", tab_count, tabs, name, ft_arraylen_d((void **)arr));
	pos = 0;
	while(arr[pos])
	{
		printf("%i %s       %li: %s\n", tab_count, tabs, pos, arr[pos]);
		pos++;
	}
}

void io_print(t_io* io, char *tabs, int tab_count)
{
	io_print_arr(io->input_files, "Input files", tabs, tab_count);
	io_print_arr(io->input_stdin, "Input stdin", tabs, tab_count);
	io_print_arr(io->output_files, "Output files", tabs, tab_count);
	io_print_arr(io->output_endfiles, "Output files (end)", tabs, tab_count);
}