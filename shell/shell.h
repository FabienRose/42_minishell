/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/02/19 09:02:29 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/27 16:03:32 by kgauthie         ###   ########.fr       */
=======
/*   Created: 2025/02/20 19:59:24 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/27 15:30:23 by kgauthie         ###   ########.fr       */
>>>>>>> errerbranch
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

# include "builtins/builtins.h"
# include "env/env.h"
//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_shell
{
	char				*last_error;
	t_dir				*current_dir;
	struct	sigaction	sa;
	char				**environement;
	t_bool				initialized;
<<<<<<< HEAD
=======
	char				**environement;
>>>>>>> errerbranch
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

//====================== START ======================
/**
 * @brief Start the shell program (Main loop)
 * 
 * @param shell Global shell structure
 * @return t_bool FALSE if Failed
 */
t_bool shell_start(t_shell* shell);

//====================== SIGNALS ======================
/**
 * @brief Initialize the signal within the t_shell struct
 * 
 * @param ptr to the main t_shell structure
 * @return t_bool = FALSE if fail
 */
t_bool shell_init_sig(t_shell* ptr);
/**
 * @brief Function called by the sigaction system
 * 
 * @param sig Signal ID
 */
void	shell_sig_handler(int sig);

//====================== ENV ======================
/**
 * @brief Fecth the environement for to generate a header to the prompt
 * 
 * @return char* Header to display (data is malloc)
 */
char *shell_gethead(t_shell *shell);
/**
 * @brief Call to update the shell->current_dir with PWD
 * 
 * @param shell Global shell structure
 * @return t_bool FALSE if Failed
 */
t_bool shell_update_loc(t_shell *shell);

//====================== CLEAR ======================
/**
 * @brief Creal agiven shell struct
 * 
 * @param shell A pointer to the struct
 */
void shell_clear(t_shell *shell);

#endif //SHELL_H
