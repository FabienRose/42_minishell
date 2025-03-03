/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:40:20 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/03 13:24:42 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
# include "common.h"
# include "builtins/builtins.h"
# include "prompt/prompt.h"
# include "shell/shell.h"
//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------

struct					s_pmt;
typedef struct s_pmt	t_pmt;
struct					s_shell;
typedef struct s_shell	t_shell;
//--------------------------------------------------

//                    FUNCTIONS
//--------------------------------------------------

t_bool	exec_builtins(t_cmd *cmd, t_shell *shell);
t_bool	exec_cmd(t_cmd *cmd, t_shell *shell);


#endif //EXEC_H
