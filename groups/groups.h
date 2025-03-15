/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:06:53 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 12:39:23 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPS_H
# define GROUPS_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

#include "token/tokens.h"
#include "reader/groups_reader.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_grp
{
	t_grp_reader *reader;
	char *input;
	t_token *token;
	void *l_shell;
}	t_grp;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and Intialize a group structure
 * 
 * @param shell Referebce to the main shell structure
 * @return t_grp* Newly created group[]
 */
t_grp *grp_create(void *shell);
/**
 * @brief Initialize a group structure
 * 
 * @param grp Group to initialize
 * @param shell Referebce to the main shell structure
 * @return t_bool FALSE if failed
 */
t_bool grp_init(t_grp *grp, void *shell);

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

//====================== DEBUG ======================
/**
 * @brief Print debug information of the current group
 * 
 * @param grp Group to print
 * @param tab_count Group sub level indentation
 */
void grp_debug(t_grp *grp, int tab_count);

#endif //GROUPS_H
