/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:32:53 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/19 16:07:05 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_io
{
	char **input_files;
	char **output_files;
	char **output_endfiles;
	char **input_stdin;
}	t_io;


//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and initialize a new IO strutcure
 * 
 * @return t_io* Newly created IO structure
 */
t_io *io_create();
/**
 * @brief Initialize a new IO structure
 * 
 * @param io IO Struct to initialize
 * @return t_bool FALSE if failed
 */
t_bool io_init(t_io* io);

//====================== CLEAR ======================
/**
 * @brief Clear and release a IO structure
 * 
 * @param io IO structure to clear
 */
void io_clear(t_io **io);

//====================== DEBUG ======================
/**
 * @brief Print debug informartion of a IO Structure
 * 
 * @param io IO structure to print
 * @param tabs Tabs string to display before the informations
 * @param tab_count The current sub group indentation
 */
void io_print(t_io* io, char *tabs, int tab_count);

#endif //IO_H
