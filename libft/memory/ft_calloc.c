/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:40:38 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/20 14:47:28 by fmixtur          ###   ########.ch       */
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
