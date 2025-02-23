/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:38:25 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/23 19:38:42 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
# include "common.h"
# include "builtins/builtins.h"
# include "env/env.h"
//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_shell
{
	t_bool	initialized;
	char	**environement;
}	t_shell;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Innitialize t_shell struct
 * 
 * @return FALSE if failed
 */
t_bool	shell_init(t_shell *shell);

#endif //SHELL_H
