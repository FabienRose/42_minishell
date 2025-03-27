/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:00:55 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/26 17:25:52 by fmixtur          ###   ########.ch       */
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

t_bool	change_directory(t_shell *shell, char **arg);
t_bool	echo(char **args);
t_bool	pwd(char **arguments);
t_bool	export(t_shell *shell, char **arg);
void	bubble_sort(char **array);
t_bool	is_valid_identifier(char *str);
t_bool	unset(t_shell *shell, char **args);
t_bool	print_env(t_shell *shell, char **args);

#endif //BUILTINS_H
