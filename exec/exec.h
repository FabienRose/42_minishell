/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:05:48 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/19 14:22:25 by kgauthie         ###   ########.fr       */
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

//TODO: to remove
typedef struct s_cmd_old
{
	char *name;
	char **arguments;
	char **full_args;
	int		previous_pipe;
	t_bool	var_isset;
	char	*var_name;
	char	*var_data;
	struct s_cmd_old **input_files;
	struct s_cmd_old **output_files;
	struct s_cmd_old **output_endfiles;
	struct s_cmd_old **input_stdin;
	struct s_cmd_old *pipe_to;
	struct s_cmd_old *or_to;
	struct s_cmd_old *and_to;
} t_cmd_old;
//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------

t_bool	exec_builtins(t_cmd_old *cmd, t_shell *shell);
t_bool	exec_cmd(t_cmd_old *cmd, t_shell *shell);
t_promptret	set_and_execute(t_cmd_old *cmd, t_pmt *pmt);
int		get_file_fd(t_cmd_old *cmd, char type);
t_bool	set_fd(t_cmd_old *cmd, t_fd *fd);
t_bool	reset_fd(t_fd *fd);
t_bool	redirect_fd_output(t_cmd_old *cmd);
t_bool	redirect_fd_input(t_cmd_old *cmd);
#endif //EXEC_H
