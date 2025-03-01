/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:39:27 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/28 16:39:49 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool ft_realloc(void **ptr, size_t old_len, size_t new_len)
{
	void	*cptr;
	void	*nptr;
	size_t	target_len;

	cptr = *ptr;
	nptr = ft_calloc(1, new_len);
	if(!nptr)
		return (FALSE);
	target_len = old_len;
	if(new_len < old_len)
		target_len = new_len;
	if(!ft_memmove(nptr, cptr, target_len))
	{
		free(nptr);
		return (FALSE);
	}
	free(cptr);
	*ptr = nptr;
	return (TRUE);
}

t_bool ft_realloc_s(void **ptr, size_t old_len, size_t new_len, size_t data_size)
{
	return ft_realloc(ptr, old_len * data_size, new_len * data_size);
}

t_bool ft_realloc_da(void ***ptr, size_t old_len, size_t new_len)
{
	return ft_realloc_s((void **)ptr, old_len, new_len, sizeof(void *));
}
