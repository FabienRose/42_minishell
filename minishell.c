/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:28:50 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/26 17:31:21 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(void)
{
	t_shell	minishell;

	shell_init(&minishell);
	printf("\n=== Testing EXPORT ===\n");
	export(&minishell, "TEST1=hello");
	printf("TEST1=%s\n", getenv("TEST1"));
	export(&minishell, "TEST1=world");
	printf("TEST1=%s\n", getenv("TEST1"));
	export(&minishell, "TEST2=");
	printf("TEST2='%s'\n", getenv("TEST2"));
	export(&minishell, "TEST3");
	export(&minishell, "2TEST=invalid");
	export(&minishell, "");
	printf("\n=== Testing ENV ===\n");
	print_env(&minishell);
	printf("\n=== Testing ECHO ===\n");
	echo(&minishell, "Hello World");
	echo(&minishell, "-n Hello World");
	echo(&minishell, "-nnnnn Hello World");
	echo(&minishell, "-n -n Hello World");
	printf("\n");
	printf("\n=== Testing CD ===\n");
	printf("Current directory: \n");
	pwd();
	change_directory(&minishell, "..");
	printf("cd .. : \n");
	pwd();
	change_directory(&minishell, "-");
	printf("cd - : \n");
	pwd();
	change_directory(&minishell, "~");
	printf("cd ~ : \n");
	pwd();
	printf("\n=== Testing PWD ===\n");
	pwd();
	free_environ(minishell.environement);
	return (0);
}
