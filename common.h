/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:42:20 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/27 12:39:38 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void util_seterror(void *shell, const char *msg);
void util_clearerror(void *shell);
void util_printerror(void *shell);

	//--------------------- Strings ---------------------
void util_printsplit(char **split);

#endif //COMMON_H
