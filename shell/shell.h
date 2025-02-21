/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:59:24 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/20 19:59:24 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
# include "common.h"

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
t_bool	init_shell(t_shell *shell);

//=================== EXEC UTILS ===================

void	set_working_directory(t_shell *shell);
t_bool	change_directory(t_shell minishell, char *arguments);
t_bool	set_environement(t_shell *minishell, char *variable, char *path);


#endif //SHELL_H
