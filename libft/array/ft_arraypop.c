/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:38:26 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/06 09:46:52 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_arraypopfront_d(void ***arr)
{
	void **c_arr;
	void **n_arr;
	void *ret;
	size_t current_len;
	size_t pos;
	

	if(!arr || !(*arr) || ft_arraylen_d(*arr) == 0)
		return (NULL);
	current_len = ft_arraylen_d(*arr);
	c_arr = *arr;
	ret = c_arr[0];
	n_arr = ft_calloc(sizeof(void *), current_len + 1);
	if(!n_arr)
		return (NULL);
	pos = 1;
	while(c_arr[pos])
	{
		n_arr[pos - 1] = c_arr[pos];
		pos++;
	}
	free(c_arr);
	*arr = n_arr;
	return ret;
}
