/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:42:20 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/01 15:34:33 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: Make sure that command works grep "void"> test.txt < minishell.txt < common.txt > test2.txt


#ifndef COMMON_H
# define COMMON_H

//--------------------------------------------------
//                 COMMON INCLUDES
//--------------------------------------------------
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

//--------------------------------------------------
//                      LIBS
//--------------------------------------------------
# include "libft/libft.h"

//--------------------------------------------------
//                   DEFIENS
//--------------------------------------------------
//====================== SETTINGS ======================
#define PROMPT_DISP_FULL TRUE

#define PROMPT_USER_COL FONT_CYN
#define PROMPT_NAME_COL FONT_YEL
#define PROMPT_DIR_COL FONT_BLU

#define PROMT_BUFFER_SIZE 32

//====================== DEVELOPMNET ======================
# ifndef RELEASE
#  define DEBUG
#  define IS_DEBUG 1
# endif

//--------------------------------------------------
//                     ENUM
//--------------------------------------------------
typedef enum e_promptret
{
	PMT_SUCCESS,
	PMT_FAILED,
	PMT_STOP,
	PMT_ERROR,	
}	t_promptret;

//--------------------------------------------------
//                  GLOBAL VARIABLS
//--------------------------------------------------
extern int gv_onint;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== SIGNATURES ======================
/**
 * @brief Print welcome message a the begining of the program
 * 
 */
void	print_welcome(void);

//====================== UTILS ======================
	//--------------------- Errors ---------------------
/**
 * @brief Set an error message in the shell structure
 * 
 * @param shell Reference to the main shell structure
 * @param msg Message to set
 */
void util_seterror(void *shell, const char *msg);
/**
 * @brief Remove any active error message
 * 
 * @param shell Reference to the main shell structure
 */
void util_clearerror(void *shell);
/**
 * @brief Print the active error message, if none setwill print perror
 * 
 * @param shell Reference to the main shell structure
 */
void util_printerror(void *shell);
/**
 * @brief Set Print and clear an error message
 * 
 * @param shell Reference to the main shell structure
 * @param msg Message to set
 */
void util_printerrorstr(void *shell, const char *msg);

	//--------------------- Strings ---------------------
void util_printsplit(char **split);

#endif //COMMON_H
