/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:06:23 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/04 19:06:06 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
/**
 * @brief Command structure
 * 
 * @param input_files t_cmd** input commands (SHOULD BE A FILE) from which the data should come from (Token: '<')
 * @param output_files t_cmd** output commands (SHOULD BE A FILE) to which the data should go to  (Token: '>')
 * @param output_files t_cmd** output commands (SHOULD BE A FILE) to which the data should go to and added at the end of the file (Token: '>>')
 * @param input_stdin t_cmd** output commands (SHOULD A TEXT) to which the program will read the stdin util it reaches the given text (Token: '<<')
 * @param pipe_to t_cmd* command to which this command will pipe to (Token: '|')
 * @param or_to t_cmd* next command to execute if this one failed (Token: '||')
 * @param and_to t_cmd* next command to execute if this one succeded (Token: '&&')
 */
typedef struct s_cmd
{
	char *name;
	char **arguments;
	char **full_args;
	int		previous_pipe;
	struct s_cmd **input_files;
	struct s_cmd **output_files;
	struct s_cmd **output_endfiles;
	struct s_cmd **input_stdin;
	struct s_cmd *pipe_to;
	struct s_cmd *or_to;
	struct s_cmd *and_to;
} t_cmd;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and initialize (cmd_init) a t_cmd structure
 * 
 * @return t_cmd* Newly created struct
 */
t_cmd	*cmd_create();/**
* @brief Create and initialize (cmd_init) a t_cmd structure
* 
* @return t_cmd* Newly created struct
*/
void	*cmd_new();
/**
 * @brief Initialize a t_cmd structure
 * 
 * @param cmd t_cmd to initialize
 * @return t_bool FALSE if fail
 */
t_bool	cmd_init(t_cmd* cmd);

//====================== ARGS ======================
/**
 * @brief Add an argument in the t_cmd structure (realloc arg size)
 * 
 * @param cmd t_cmd to add arguments in
 * @param arg argument to add
 * @return t_bool FALSE on Failed
 */
t_bool cmd_add_arg(t_cmd *cmd, char *arg);

/**
 * @brief Will create a new array with the name and arguments of the command (If already exist it will return the array stored in the t_cmd)
 * @brief DO NOT RELEASE THE Char* contained in the array this is the reference as 'name' & 'arguments'
 * 
 * @param cmd Structure to merge data
 * @return char** An array of all string data
 */
char **cmd_get_fullarray(t_cmd *cmd);

//====================== CLEAR ======================
/**
 * @brief Clear a t_cmd struct and free the struct from its suffering
 * 
 * @param cmd Pointer of pointer of the t_cmd structure to clear
 */
void	cmd_clear(t_cmd **cmd);
/**
 * @brief libft compatible version of cmd_clear;
 * 
 * @param cmd Pointer of pointer of the t_cmd structure to clear
 */
void	cmd_release(void *cmd);

//====================== DEBUG ======================
/**
 * @brief Print a t_cmd structure details
 * @warning Do not use in final product
 * 
 * @param cmd t_cmd to print
 */
void cmd_print(t_cmd* cmd);

#endif //COMMAND_H
