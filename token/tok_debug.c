/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:03:41 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/17 15:32:31 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"

void tok_print(t_token *token, char *tabs, int tab_count)
{
	printf("%i %s    Input: %s\n", tab_count, tabs, token->input);
	printf("%i %s    Type: %i\n", tab_count, tabs, token->type);
}