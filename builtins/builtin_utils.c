/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:03:03 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/28 11:36:52 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(char **array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		j = -1;
		while (array[++j + 1])
			if (ft_strncmp(array[j], array[j + 1], ft_strlen(array[j])) > 0)
				swap(&array[j], &array[j + 1]);
	}
}
