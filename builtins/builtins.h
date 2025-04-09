/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:32:25 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 20:14:07 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
# include "common.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------

struct					s_shell;
typedef struct s_shell	t_shell;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== CD ======================
/**
 * @brief Change the directory
 * 
 * @param shell t_shell structure
 * @param arg path to change to
 * @return t_bool TRUE if the directory was changed, FALSE it fails
 */
t_bool		builtin_change_directory(t_shell *shell, char **arg);
//====================== ECHO ======================
/**
 * @brief Print the arguments
 * 
 * @param args arguments to print
 * @return t_bool TRUE if the arguments were printed, FALSE it fails
 */
t_bool		builtin_echo(char **args);
//====================== PWD ======================
/**
 * @brief Print the working directory
 * 
 * @param arguments arguments to print
 * @return t_bool TRUE if the working directory was printed, FALSE it fails
 */
t_bool		builtin_pwd(char **arguments);
//====================== EXPORT ======================
/**
 * @brief add or update a variable to the environment
 * 
 * @param shell t_shell structure
 * @param arg variable to add or update
 * @return t_bool TRUE if the arguments were exported, FALSE it fails
 */
t_bool		builtin_export(t_shell *shell, char **arg);
t_bool		add_env(t_shell *shell, char *arg);
//====================== UNSET ======================
/**
 * @brief Unset the environment variable
 * 
 * @param shell t_shell structure
 * @param args variable to unset
 * @return t_bool TRUE if the variable was unset, FALSE it fails
 */
t_bool		builtin_unset(t_shell *shell, char **args);
//====================== EXIT ======================
/**
 * @brief Exit the shell
 * 
 * @param shell t_shell structure
 * @param args arguments to exit
 */
t_promptret	builtin_exit(t_shell *shell, char **args);
//====================== PRINT_ENV ======================
/**
 * @brief Print the environment
 * 
 * @param shell t_shell structure
 * @param args arguments to print
 */
t_bool		print_env(t_shell *shell, char **args);
//====================== HELPER FUNCTIONS ======================
/**
 * @brief Check if the variable name is valid
 * 
 * @param str variable name to check
 * @return t_bool TRUE if the variable name is valid, FALSE it fails
 */
t_bool		is_valid_identifier(char *str);
/**
 * @brief Sort the array of variables
 * 
 * @param array array of variables to sort
 */
void		bubble_sort(char **array);

#endif //BUILTINS_H
