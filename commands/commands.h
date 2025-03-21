/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:35:08 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/21 14:58:45 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_cmd
{
	char 	*name;
	char 	**args;
	char	**full;
	void	*l_shell;
	t_bool	var_isset;
	char	*var_name;
	char	*var_data;
}	t_cmd;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and Initialize a command structur 
 * 
 * @param shell Reference to shell
 * @return t_cmd*  Newly created command
 */
t_cmd *cmd_create(void *shell);
/**
 * @brief Initialize a given command structure
 * 
 * @param cmd Command to initialize
 * @param shell Reference to shell
 * @return t_bool* FALSE if failed
 */
t_bool cmd_init(t_cmd *cmd, void *shell);

//====================== ADD ======================
/**
 * @brief Add data either to the name or the args (automatic), and copy the data into the full array
 * 
 * @param cmd Command to add the data in
 * @param data Data to add
 * @return t_bool FALSE if failed
 */
t_bool cmd_add(t_cmd* cmd, char *data);

//====================== VARS ======================
/**
 * @brief Check if the command actually required to set an environmental variable
 * 
 * @param cmd command to check
 * @return t_bool FALSE if failed
 */
t_bool cmd_check_setvar(t_cmd *cmd);

//====================== CLEAR ======================
/**
 * @brief Release a command structure
 * 
 * @param cmd Pointer to the pointer handling the command to free
 */
void	cmd_clear(t_cmd **cmd);

//====================== NAME ======================
/**
 * @brief Print the debug of a command structure
 * 
 * @param cmd Coomand to print
 * @param tabs Tabs string to display before the informations
 * @param tab_count The current sub group indentation
 */
void cmd_print(t_cmd* cmd, char *tabs, int tab_count);

#endif //COMMANDS_H
