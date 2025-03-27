/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:25:16 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/27 07:35:05 by fmixtur          ###   ########.ch       */
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

typedef enum e_promptret t_promptret;

typedef struct s_fd
{
	int		pipe_fd[2];
	int		saved_stdin;
	int		saved_stdout;
}	t_fd;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------

t_bool	exec_builtins(t_cmd *cmd, t_shell *shell);
t_bool	exec_cmd(t_cmd *cmd, t_shell *shell);
t_promptret	set_and_execute(t_grp *grp);
int		get_file_fd(t_cmd *cmd, char type);
t_bool	set_fd(t_cmd *cmd, t_fd *fd);
t_bool	reset_fd(t_fd *fd);
t_bool	redirect_fd_output(t_grp *grp);
t_bool	redirect_fd_input(t_grp *grp);
#endif //EXEC_H
