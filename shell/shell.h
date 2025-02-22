/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:02:29 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/21 17:52:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
# include "common.h"

# include "directories/directories.h"
# include "prompt/prompt.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_shell
{
	t_bool	initialized;
	char	*last_error;
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

//====================== NAME ======================
/**
 * @brief Start the shell program (Main loop)
 * 
 * @param shell Global shell structure
 * @return t_bool FALSE if Failed
 */
t_bool shell_start(t_shell* shell);

//====================== CLEAR ======================
/**
 * @brief Creal agiven shell struct
 * 
 * @param shell A pointer to the struct
 */
void shell_clear(t_shell *shell);

#endif //SHELL_H
