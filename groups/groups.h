/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:06:53 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/20 15:58:49 by kgauthie         ###   ########.fr       */
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
#include "commands/commands.h"
#include "io/io.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_grp
{
	t_grp_reader *reader;
	char *input;
	char *input_before;
	char *input_after;
	char *input_uniq;
	char *input_after_io;
	t_token *token;
	struct s_grp	*grp_before;
	struct s_grp	*grp_after;
	struct s_grp	*grp_uniq;
	t_cmd			*cmd;
	t_io			*io;
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

//====================== VARS & TILD ======================
/**
 * @brief Copy the given input and will replace any variable or tilde contain in it (only if is_first is set)
 * 
 * @param grp Grp to set the input into
 * @param input String of the input
 * @param is_first TRUE if we need to set variables
 */
t_promptret grp_parseinput(t_grp* grp, const char *input, t_bool is_first);
/**
 * @brief Will add a tild information (HOME) into the reader buffer
 * 
 * @param grp Group containing the reader
 * @return t_promptret Status of the function
 */
t_promptret grp_addtild(t_grp* grp);

//====================== SETTERS ======================
	//---------------------  Main ---------------------
/**
 * @brief Main function  called to start parsing of a group data
 * 
 * @param grp Group to parse in
 * @param input Input string of the group
 * @param is_first TRUE if we need to set variables
 * @return t_bool FALSE if Failed
 */
t_promptret grp_set_input(t_grp *grp, const char *input, t_bool is_first);

	//--------------------- Split ---------------------
/**
 * @brief Check within the input for a specific token and then split into two substring
 * 
 * @param grp Group to split in two
 * @param token Target charcter (begining of the token)
 * @param target_type t_token_type of the desired token
 * @return t_promptret Return status of the function
 */
t_promptret grp_set_split(t_grp *grp, char token, t_token_type target_type);

	//--------------------- Uniq ---------------------
/**
 * @brief Check if there is any sub group within parenthesis
 * 
 * @param grp Group to check
 * @return t_promptret Return status of the function
 */
t_promptret grp_check_uniq(t_grp* grp);

	//--------------------- COMMANDS ---------------------
/**
 * @brief Split the active command
 * 
 * @param grp Group to check
 * @return t_promptret Return status of the function
 */
t_promptret grp_getcmd(t_grp *grp);

	//--------------------- IO ---------------------
/**
 * @brief Get and remove any flow redirection
 * 
 * @param grp Group to check
 * @return t_promptret Return status of the function
 */
t_promptret grp_getio(t_grp *grp);

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

//====================== SUBS ======================
//--------------------- io ---------------------
t_bool grp_getio_merge(t_grp *grp);
t_promptret grp_getio_applytoio(t_grp *grp, t_token *token);

#endif //GROUPS_H
