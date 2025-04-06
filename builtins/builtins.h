/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:00:55 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 10:19:54 by kgauthie         ###   ########.fr       */
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
t_bool	blt_echo(char **args);
t_bool	pwd(char **arguments);
t_bool	add_env(t_shell *shell, char *arg);
t_bool	export(t_shell *shell, char **arg);
void	bubble_sort(char **array);
t_bool	is_valid_identifier(char *str);
t_bool	unset(t_shell *shell, char **args);
t_bool	print_env(t_shell *shell, char **args);

#endif //BUILTINS_H
