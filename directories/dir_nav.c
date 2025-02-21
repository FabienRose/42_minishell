/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_nav.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:16:20 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 09:20:35 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directories.h"

char *dir_getat(t_dir *dir, size_t pos)
{	
	if(!dir || !dir->detailed_path)
		return (NULL);
	return dir->detailed_path[pos];
}

size_t	dir_getlen(t_dir *dir)
{
	size_t i;
	if(!dir || !dir->detailed_path)
		return (0);
	i = 0;
	while(dir->detailed_path[i])
		i++;
	return(i);
}