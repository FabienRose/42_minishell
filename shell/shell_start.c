/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:44:39 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 18:26:15 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bool shell_start(t_shell* shell)
{
	t_pmt* current_pmt;

	current_pmt = pmt_new("TEST", shell);
	if(!current_pmt)
		return (FALSE);
	pmt_clear(&current_pmt);
	current_pmt = NULL;
	return (TRUE);
}
