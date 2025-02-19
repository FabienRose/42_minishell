/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:53:27 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/19 11:24:29 by kgauthie         ###   ########.fr       */
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
	return (0);
}
