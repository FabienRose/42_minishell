/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:16:06 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/26 17:16:06 by fmixtur          ###   ########.ch       */
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

t_bool	set_environement(t_shell *minishell, char *variable, char *path,
			int path_is_malloc);
t_bool	copy_environ(t_shell *minishell);
t_bool	free_environ(char **environ);
char	*create_env(char *variable, char *value);
char	**resize_environ(int new_size);
t_bool	unset_environement(t_shell *minishell, char *variable);
t_bool	update_existing_env(char **environ, char *variable, char *entry);

#endif //ENV_H
