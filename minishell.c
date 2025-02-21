/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:34:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/20 20:36:22 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(void)
{
	t_shell	minishell;
	int i = 0;

	minishell.environement = NULL;
	// printf("Before : %s\n", getenv(test));
	set_environement(&minishell, "FABIEN","La variable est set!");
	while (minishell.environement[i])
	{
		printf(">>> %d: %s\n",i, minishell.environement[i]);
		free(minishell.environement[i]);
		i++;
	}
	free(minishell.environement);
	
	// set_environement("OLDPWD","/home/fmixtur");
	// printf("After again : %s\n", getenv(test));
	return (0);
}

