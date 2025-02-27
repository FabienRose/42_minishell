/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:53:27 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/27 15:32:45 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	data;
	print_welcome();
	
	if(!shell_init(&data))
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
	return (0);
	//TODO: Check memory error on resize_environ with strdup
}

