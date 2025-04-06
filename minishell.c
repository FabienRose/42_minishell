/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:12:46 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/01 00:13:07 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell data;
	
	print_welcome();
	if(!shell_init(&data, &envp))
	{
		printf("%s%sError: Cannot init shell%s\n", FONT_RED, FONT_BOLD, FONT_NRM);
		return (1);
	}
	if(!shell_start(&data))
	{
		util_printerror(&data);
		shell_clear(&data);
		return (1);
	}
	shell_clear(&data);

	(void)argc;
	(void)argv;
	(void)envp;
	return (data.last_return);
	//TODO: Check memory error on resize_environ with strdup
}
