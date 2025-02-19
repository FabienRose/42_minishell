/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:05:49 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/04 18:17:26 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*retptr;

	retptr = malloc(nmemb * size);
	if (!retptr)
		return (NULL);
	ft_bzero(retptr, nmemb * size);
	return (retptr);
}
