/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:39:33 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/22 16:45:32 by fmixtur          ###   ########.ch       */
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

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------

struct s_shell;
typedef struct s_shell t_shell;

t_bool	set_environement(t_shell *minishell, char *variable, char *path);
t_bool  copy_environ(t_shell *minishell);
t_bool  free_environ(char **environ);
char	*create_env(char *variable, char *value);
char	**resize_environ(int new_size);
t_bool	unset_environement(t_shell *minishell, char *variable);






#endif //ENV_H
