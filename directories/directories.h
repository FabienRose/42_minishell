/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directories.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:32:13 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 10:00:28 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORIES_H
# define DIRECTORIES_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_dir
{
	char	**detailed_path;
	char	*path;
	char	*name;
	t_bool	is_file; //TODO: Add chechking during that the directory is a file
}	t_dir;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create new t_dir structure and initialize it (using a given path)
 * 
 * @param path Directory path to create from
 * @return t_dir* Newly created structure (and initialized)
 */
t_dir* dir_new(const char* path);
/**
 * @brief Initialize structure of type t_dir using a given path
 * 
 * @param dir t_dir to initilize
 * @param path path to initialized to (If empty the function will fail)
 * @return t_bool return status of the initialization (FALSE == Failed)
 */
t_bool dir_init_from_path(t_dir* dir, const char* path);

//====================== NAVIGATION ======================
/**
 * @brief Get the directory at N pos
 * @warning The returned string is a local reference and while be freed on dir_clear
 * 
 * @param dir t_dir to searh in
 * @param pos position of the folder name
 * @return char* The found char* of the folder name
 */
char	*dir_getat(t_dir *dir, size_t pos);
/**
 * @brief Get the total size of the folder count
 * 
 * @param dir The t_dir to count from
 * @return size_t the total count of folder in the path
 */
size_t	dir_getlen(t_dir *dir);

//====================== CLEAR ======================
/**
 * @brief Clear a t_dir structure (on a secure way)
 * 
 * @param dir Ref to the pointer where your t_dir* is stored (! Pointer of Pointer !)
 */
void dir_clear(t_dir **dir);

#endif //DIRECTORIES_H
