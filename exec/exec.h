/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:02:29 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 15:06:26 by kgauthie         ###   ########.fr       */
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

struct						s_pmt;
typedef struct s_pmt		t_pmt;
struct						s_shell;
typedef struct s_shell		t_shell;
typedef enum e_promptret	t_promptret;

typedef struct s_fd
{
	int		pipe_fd[2];
	int		saved_stdin;
	int		saved_stdout;
}	t_fd;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
	//--------------------- Setup ---------------------
/**
 * @brief Execute a group containing either a token or a 
 * command with or without redirections
 * 
 * @param grp Group to execute
 * @return t_promptret Status of the execution
 */
t_promptret	exec_setup(t_grp *grp);
	//--------------------- Execution ---------------------
/**
 * @brief Execute a builtins command
 * 
 * @param cmd Command to execute
 * @param shell Reference to the main shell structure
 * @return t_bool TRUE if the command is a builtins, FALSE otherwise
 */
t_bool		exec_builtins(t_cmd *cmd, t_shell *shell);
/**
 * @brief Execute a command
 * 
 * @param cmd Command to execute
 * @param shell Reference to the main shell structure
 * @return t_bool TRUE if the command is a builtins, FALSE otherwise
 */
t_promptret	exec_cmd(t_cmd *cmd, t_shell *shell);
	//--------------------- Redirections ---------------------
/**
 * @brief Redirect the output of a command
 * 
 * @param grp Group to redirect
 * @return t_promptret Status of the redirection
 */
t_promptret	redirect_fd_output(t_grp *grp);
/**
 * @brief Redirect the input of a command
 * 
 * @param grp Group to redirect
 * @return t_promptret Status of the redirection
 */
t_promptret	redirect_fd_input(t_grp *grp);
/**
 * @brief Get the file descriptor of an output file
 * 
 * @param grp Group to get the file descriptor from
 * @param type Type of the file descriptor
 * @param file_fd File descriptor to get
 */
t_bool		get_outfile_fd(t_grp *grp, char type, int *file_fd);
/**
 * @brief Get the file descriptor of an input file
 * 
 * @param grp Group to get the file descriptor from
 * @return int File descriptor of the input file
 */
int			get_infile_fd(t_grp *grp);
/**
 * @brief Get the file descriptor of the standard input
 * 
 * @param grp Group to get the file descriptor from
 * @return int File descriptor of the standard input
 */
int			get_stdin_fd(t_grp *grp);
/**
 * @brief Reset the file descriptors
 * 
 * @param fd File descriptors to reset
 * @return t_bool TRUE if the file descriptors are reset, FALSE otherwise
 */
t_bool		reset_fd(t_fd *fd);
#endif //EXEC_H
