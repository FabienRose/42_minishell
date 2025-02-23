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
	// int i = 0;

	minishell.environement = NULL;
	copy_environ(&minishell);
	set_environement(&minishell, "FABIEN","La variable est reset!");
	set_environement(&minishell, "TEST","La variable est reset!");
	// while (minishell.environement[i])
	// {
	// 	printf(">>> %d: %s\n",i, minishell.environement[i]);
	// 	free(minishell.environement[i]);
	// 	i++;
	// }
	printf("Get env test : %s\n", getenv("FABIEN"));
	printf("Get env test : %s\n", getenv("TEST"));
	unset_environement(&minishell, "TEST");
	printf("Get env test : %s\n", getenv("TEST"));
	// free_environ(minishell.environement);
	// set_environement("OLDPWD","/home/fmixtur");
	// printf("After : %s\n", getenv("PWD"));
	return (0);
}

