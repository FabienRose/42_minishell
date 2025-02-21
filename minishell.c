/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:53:27 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/21 17:40:34 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/shell.h"

int	main(void)
{
	t_shell data;
	
	print_welcome();
	
	char *str = ft_strdup("");
	if(!str)
		return 1;
	if(!ft_strmerge(&str, "Test ", FONT_BLU, "word")
		|| !ft_strmerge(&str, FONT_NRM, " world", NULL))
	{
		free(str);
		return 1;
	}
	printf("%s\n", str);
	free(str);


	if(!shell_init(&data))
	{
		printf("%s%sError: Cannot init shell%s\n", FONT_RED, FONT_BOLD, FONT_NRM);
		return (1);
	}
	shell_clear(&data);
	return (0);
}
