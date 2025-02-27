/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:16:25 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/27 16:41:43 by kgauthie         ###   ########.fr       */
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

t_bool	change_directory(t_shell *shell, char *arg);
t_bool	echo(t_shell *shell, char *args);
t_bool	pwd(void);
t_bool	export(t_shell *shell, char *arg);
void	bubble_sort(char **array);
t_bool	is_valid_identifier(char *str);
t_bool	unset(t_shell *shell, char *args);
t_bool	print_env(t_shell *shell);

#endif //BUILTINS_H
