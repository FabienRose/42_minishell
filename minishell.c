/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:45:41 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/19 11:48:13 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	main(int argc, char **argv)
{
	print_welcome();
	(void)argc;
	(void)argv;
	printf("Hello World!");
	printf("Hey my guy !!");
	printf("Sunny init?");
	return (0);
}
