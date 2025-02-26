/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:24:35 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/26 17:28:41 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
