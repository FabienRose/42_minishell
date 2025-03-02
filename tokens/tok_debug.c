/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:03:41 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 14:25:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void tok_print(t_token *token)
{
	printf("Input: %s\n", token->input);
	printf("Type: %i\n", token->type);
	printf("Prev: %p\n", token->prev);
	printf("Next: %p\n", token->next);
}