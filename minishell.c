/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:19:31 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/23 11:19:43 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(void)
{
	t_shell	minishell;

	shell_init(&minishell);
	printf("Current dir : %s\n", getenv("PWD"));
	printf("Previous dir : %s\n\n", getenv("OLDPWD"));
	change_directory(&minishell, "env");
	printf("current dir : %s\n", getenv("PWD"));
	printf("previous dir : %s\n\n", getenv("OLDPWD"));
	change_directory(&minishell, "..");
	printf("current dir : %s\n", getenv("PWD"));
	printf("previous dir : %s\n\n", getenv("OLDPWD"));
	change_directory(&minishell, "~/42");
	printf("current dir : %s\n", getenv("PWD"));
	printf("previous dir : %s\n\n", getenv("OLDPWD"));
	change_directory(&minishell, "..");
	printf("current dir : %s\n", getenv("PWD"));
	printf("previous dir : %s\n\n", getenv("OLDPWD"));
	change_directory(&minishell, "..");
	printf("current dir : %s\n", getenv("PWD"));
	printf("previous dir : %s\n\n", getenv("OLDPWD"));
	free_environ(minishell.environement);
	return (0);
}
