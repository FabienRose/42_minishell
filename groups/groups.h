/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:13:43 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/11 15:54:17 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPS_H
# define GROUPS_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"
#include "command/command.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_grp_parse
{
	void *l_pmt;
	size_t total_token;
	size_t token_pos;
	size_t cmd_pos;
} t_grp_parse;

typedef struct s_grp
{
	struct s_grp **input_files;
	struct s_grp **output_files;
	struct s_grp **output_endfiles;
	struct s_grp **input_stdin;
	struct s_grp *pipe_to;
	struct s_grp *or_to;
	struct s_grp *and_to;
	t_promtret	last_ret;
} t_grp;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Common function to create and initialize a group (Calling grp_create)
 * 
 * @return void* Newly created group
 */
void *grp_new();
/**
 * @brief Function to create and initialize a group (grp_init)
 * 
 * @return t_grp* Newly created pointer (If succeded)
 */
t_grp *grp_create();
/**
 * @brief Initialize a given group struct
 * 
 * @param grp Group structure to initialize
 * @return t_bool FALSE is Failed
 */
t_bool grp_init(t_grp* grp);
/**
 * @brief Initialize the group paarse structure
 * 
 * @param parse Group Parsze to initialize
 * @param pmt Reference to the parent prompt
 * @return t_bool FALSE if failed
 */
t_bool grp_parse_init(t_grp_parse *parse, void *pmt);

//====================== PARSE ======================
/**
 * @brief Parse the current token structure to determinate the command structure
 * @brief This function is used as recursive (parse is common is common to all ocurrences)
 * 
 * @param parse Parse structure used to check all tokens
 * @param grp The current group 
 * @return t_bool FALSE id failed
 */
t_bool grp_parse(t_grp_parse *parse, t_grp* grp);

//====================== CLEAR ======================
/**
 * @brief Common function to clear a group  (Calling  grp_clear)
 * 
 * @param grp Groupe to destroy
 */
void grp_release(void *grp);
/**
 * @brief Function to clear a group stucture
 * 
 * @param grp Pointer towrd the pointer of the group struct
 */
void grp_clear(t_grp **grp);

//====================== DEBUG ======================
/**
 * @brief Print the current gorup and all sub groups
 * 
 * @param grp Group to print
 */
void grp_debug(t_grp *grp);

#endif //GROUPS_H
