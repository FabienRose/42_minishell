/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:03:41 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/11 18:14:21 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void tok_print(t_token *token)
{
	printf("Input: %s\n", token->input);
	printf("Type: %i\n", token->type);
	printf("Prev: %p\n", token->prev);
	printf("Next: %p\n", token->next);
	printf("Prev token: %p\n", token->prev_tok);
	printf("Next token: %p\n", token->next_tok);
	printf("Assigned Group: %p\n", token->assigned_group);
	printf("\n\n");
}