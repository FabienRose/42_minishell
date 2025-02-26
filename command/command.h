/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:24:56 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 08:15:26 by kgauthie         ###   ########.fr       */
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
t_cmd	*cmd_create();
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

//====================== DEBUG ======================
/**
 * @brief Print a t_cmd structure details
 * @warning Do not use in final product
 * 
 * @param cmd t_cmd to print
 */
void cmd_print(t_cmd* cmd);

#endif //COMMAND_H
