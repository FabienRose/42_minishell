/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:03:53 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/03 11:03:53 by fmixtur          ###   ########.ch       */
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
typedef struct s_cmd
{
	char *name;
	char **arguments;
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
