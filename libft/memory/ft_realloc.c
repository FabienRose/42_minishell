/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:46:45 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 16:47:14 by kgauthie         ###   ########.fr       */
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
