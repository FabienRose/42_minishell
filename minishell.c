/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:59:44 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/25 10:59:44 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(void)
{
	t_shell	minishell;

	shell_init(&minishell);
	printf("Test 1 (-n test):\n");
	echo(&minishell, "-n test");
	printf("\n\nTest 2 (-n -n test):\n");
	echo(&minishell, "-n -n test");
	printf("\n\nTest 3 (test):\n");
	echo(&minishell, "test");
	printf("\nTest 4 (-nnn test):\n");
	echo(&minishell, "-nnn test");
	printf("\n\nTest 5 (-n hello world):\n");
	echo(&minishell, "-n hello world");
	printf("\n");
	free_environ(minishell.environement);
	return (0);
}
