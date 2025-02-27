/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:11:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/26 12:31:03 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_bool	unset(t_shell *shell, char *args)
{
	if (!args)
		return (FALSE);
	if (!is_valid_identifier(args))
		return (FALSE);
	unset_environement(shell, args);
	return (TRUE);
}
