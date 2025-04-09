/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:47:12 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 19:24:50 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------

# include "common.h"
# include "shell/shell.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------

struct					s_shell;
typedef struct s_shell	t_shell;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------

//====================== environment ======================
/**
 * @brief Copy the environment from the original to the minishell environment
 * 
 * @param minishell 
 * @return t_bool 
 */
t_bool	copy_environ(t_shell *minishell);
/**
 * @brief Add or update a variable to the environment
 * 
 * @param minishell 
 * @param variable
 * @param value
 * @param value_is_malloc
 * @return t_bool 
 */
t_bool	set_environment(t_shell *minishell, char *variable, char *value,
			int value_is_malloc);
/**
 * @brief Free the environment
 * 
 * @param environ
 * @return t_bool 
 */
t_bool	free_environ(char **environ);
/**
 * @brief Create an environment variable
 * 
 * @param variable
 * @param value
 */
char	*create_env(char *variable, char *value);
/**
 * @brief Update an existing environment variable
 * 
 * @param minishell
 * @param variable
 * @param entry
 */
t_bool	update_existing_env(t_shell *minishell, char *variable, char *entry);
/**
 * @brief Resize the environment
 * 
 * @param environ
 * @param new_size
 */
char	**resize_environ(char **environ, int new_size);
/**
 * @brief Unset an environment variable
 * 
 * @param minishell
 * @param variable
 */
t_bool	unset_environment(t_shell *minishell, char *variable);
/**
 * @brief Get an environment variable
 * 
 * @param var variable to get
 * @param env environment
 * @return char*
 */
char	*my_getenv(const char *var, char **env);
#endif //ENV_H
