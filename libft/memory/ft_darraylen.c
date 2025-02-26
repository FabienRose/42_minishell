/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darraylen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:03:10 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 08:04:05 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_darraylen(void **arr)
{
	size_t pos;

	pos = 0;
	while(arr[pos])
		pos++;
	return pos;
}