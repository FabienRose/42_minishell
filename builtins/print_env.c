/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:24:35 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/27 16:43:57 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "builtins.h"
#include "shell/shell.h"

t_bool	print_env(t_shell *shell)
{
	int	i;

	if (!shell->environement)
		return (TRUE);
	i = 0;
	while (shell->environement[i])
	{
		printf("%s\n", shell->environement[i]);
		i++;
	}
	return (TRUE);
}
