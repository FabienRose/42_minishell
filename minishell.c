/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:53:27 by fmixtur           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/27 16:01:56 by kgauthie         ###   ########.fr       */
=======
/*   Updated: 2025/02/27 15:32:45 by kgauthie         ###   ########.fr       */
>>>>>>> errerbranch
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(int argc, char **argv, char **envp)
{
<<<<<<< HEAD
	t_shell data;
	
=======
	t_shell	data;
>>>>>>> errerbranch
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
