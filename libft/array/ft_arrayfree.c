/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:57:39 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/28 17:00:05 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_arrayfree(void **arr)
{
	if(*arr)
	{
		free(*arr);
		*arr = NULL;
	}
}

void ft_arrayfree_d(void ***arr, void(*del)(void *))
{
	void **carr;
	size_t pos;

	carr = *arr;
	pos = 0;
	if(!carr)
		return ;
	while(carr[pos])
	{
		(*del)(carr[pos]);
		carr[pos] = NULL;
	}
	free(carr);
	*arr = NULL;
}
