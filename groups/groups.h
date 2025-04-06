/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:30:18 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 14:49:07 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPS_H
# define GROUPS_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
# include "common.h"

# include "token/tokens.h"
# include "reader/groups_reader.h"
# include "commands/commands.h"
# include "io/io.h"
# include "builtins/builtins.h"
//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_grp
{
	t_grp_reader	*reader;
	char			*input;
	char			*input_before;
	char			*input_after;
	char			*input_uniq;
	char			*input_after_uniq;
	char			*input_after_io;
	t_token			*token;
	struct s_grp	*grp_before;
	struct s_grp	*grp_after;
	struct s_grp	*grp_uniq;
	t_cmd			*cmd;
	t_io			*io;
	t_bool			is_uniq;
	t_bool			no_varsplit;
	void			*l_shell;
}	t_grp;

typedef struct s_grp_varreader
{
	size_t	pos;
	size_t	end;
	t_bool	has_sq;
	t_bool	has_dq;
}	t_grp_varreader;

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
t_grp		*grp_create(void *shell);
/**
 * @brief Initialize a group structure
 * 
 * @param grp Group to initialize
 * @param shell Referebce to the main shell structure
 * @return t_bool FALSE if failed
 */
t_bool		grp_init(t_grp *grp, void *shell);

//====================== VARS & TILD ======================
/**
 * @brief Copy the given input and will replace any 
 * variable or tilde contain in it (only if is_first is set)
 * 
 * @param grp Grp to set the input into
 * @param input String of the input
 * @param is_first TRUE if we need to set variables
 */
t_promptret	grp_parseinput(t_grp *grp, const char *input, t_bool is_first);
/**
 * @brief Will add a tild information (HOME) into the reader buffer
 * 
 * @param grp Group containing the reader
 * @return t_promptret Status of the function
 */
t_promptret	grp_addtild(t_grp *grp);

	//--------------------- UTIL ---------------------
/**
 * @brief Proccess a variable as needed
 * 
 * @param grp Group related to the variable
 * @param value Variable data
 * @return char* Copy of the data
 */
char		*grp_var_process(t_grp *grp, char *value);
/**
 * @brief Add the last result value into the reader
 * 
 * @param grp Target groupe containing the reader
 * @return t_promptret Status of the function
 */
t_promptret	grp_apply_lastresult(t_grp *grp);

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
t_promptret	grp_set_input(t_grp *grp, const char *input, t_bool is_first);

	//--------------------- Split ---------------------
/**
 * @brief Check within the input for a 
 * specific token and then split into two substring
 * 
 * @param grp Group to split in two
 * @param token Target charcter (begining of the token)
 * @param target_type t_token_type of the desired token
 * @return t_promptret Return status of the function
 */
t_promptret	grp_set_split(t_grp *grp, char token, t_token_type target_type);

	//--------------------- Uniq ---------------------
/**
 * @brief Check if there is any sub group within parenthesis
 * 
 * @param grp Group to check
 * @return t_promptret Return status of the function
 */
t_promptret	grp_check_uniq(t_grp *grp);

	//--------------------- Check ---------------------
/**
 * @brief Check if there is any remaining data after a uniq parse and a io parse
 * 
 * @param grp Groupe to check 
 * @return t_promptret PMT_FAILED if something is found
 */
t_promptret	grp_check_residue(t_grp *grp);
/**
 * @brief Will check there is no uniq insid 
 * a uniq (Double parentesis) without a io
 * 
 * @param grp Group to check
 * @return t_promptret PMT_FAILED if double
 */
t_promptret	grp_check_double(t_grp *grp);

	//--------------------- COMMANDS ---------------------
/**
 * @brief Split the active command
 * 
 * @param grp Group to check
 * @return t_promptret Return status of the function
 */
t_promptret	grp_getcmd(t_grp *grp);

	//--------------------- IO ---------------------
/**
 * @brief Get and remove any flow redirection
 * 
 * @param grp Group to check
 * @return t_promptret Return status of the function
 */
t_promptret	grp_getio(t_grp *grp);
/**
 * @brief Reset the stdin array inside the groupe
 * 
 * @param grp Group to reset
 * @return t_promptret Status of the function
 */
t_promptret	grp_io_stdin_reset(t_grp *grp);
/**
 * @brief Call we canceling on ctrl + C
 * 
 * @param grp Groupe called with
 * @param output Output to clear
 * @return t_promptret Return status of the function
 */
t_promptret	grp_io_stdin_sigint(t_grp *grp, char **output);
/**
 * @brief Print the error message with safeword
 * 
 * @param safeword Word to print
 * @return t_promptret Return status of the function
 */
t_promptret	grp_io_stdin_error(char *safeword);
/**
 * @brief Check if any of the input has variable
 * 
 * @param grp Group to parse
 * @return t_promptret Return status of the function
 */
t_promptret	grp_io_stdin_parse(t_grp *grp);
/**
 * @brief Get required data on the standard input
 * 
 * @param grp Groupe to check in
 * @return t_promptret Status of the function 
 */
t_promptret	grp_io_stdin(t_grp *grp);

//====================== CLEAR ======================
/**
 * @brief Generical function to free a group structure (Calling grp_clear)
 * 
 * @param grp Group to free
 */
void		grp_release(void *grp);
/**
 * @brief Clear and release a group structure
 * 
 * @param grp Pointer of the pointer to the groupe structure 
 */
void		grp_clear(t_grp **grp);

//====================== DEBUG ======================
/**
 * @brief Print debug information of the current group
 * 
 * @param grp Group to print
 * @param tab_count Group sub level indentation
 */
void		grp_debug(t_grp *grp, int tab_count);

//====================== SUBS ======================
//--------------------- io ---------------------
t_bool		grp_getio_merge(t_grp *grp);
t_promptret	grp_getio_applytoio(t_grp *grp, t_token *token);

//====================== WILDCARDS ======================
/**
 * @brief Expand wildcards in a given string
 * 
 * @param grp Group to add arguments to
 * @param extract Extract to expand
 * @return t_promptret PMT_SUCCESS if success, PMT_ERROR if failed
 */
t_promptret	grp_expand_wildcard(t_grp *grp, char *extract);

#endif //GROUPS_H
