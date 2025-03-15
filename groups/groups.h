/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:06:53 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 10:55:55 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPS_H
# define GROUPS_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

#include "reader/groups_reader.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_grp
{
	t_grp_reader *reader;
	char *input;
}	t_grp;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create a new group structure (Generical signature to call grp_create)
 * 
 * @return void* Newly created group struct
 */
void *grp_new();
/**
 * @brief Create and Intialize a group structure
 * 
 * @return t_grp* Newly created group[]
 */
t_grp *grp_create();
/**
 * @brief Initialize a group structure
 * 
 * @param grp Group to initialize
 * @return t_bool FALSE if failed
 */
t_bool grp_init(t_grp *grp);

//====================== SETTERS ======================
/**
 * @brief Main function  called to start parsing of a group data
 * 
 * @param grp Group to parse in
 * @param input Input string of the group
 * @return t_bool FALSE if Failed
 */
t_promptret grp_set_input(t_grp *grp, const char *input);

//====================== CLEAR ======================
/**
 * @brief Generical function to free a group structure (Calling grp_clear)
 * 
 * @param grp Group to free
 */
void grp_release(void *grp);
/**
 * @brief Clear and release a group structure
 * 
 * @param grp Pointer of the pointer to the groupe structure 
 */
void grp_clear(t_grp **grp);
#endif //GROUPS_H
