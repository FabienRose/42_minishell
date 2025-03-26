/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:12:48 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/26 16:22:42 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

#include "groups/groups.h"
#include "builtins/builtins.h"
#include "exec/exec.h"
#include "checker/checker.h"

//--------------------------------------------------
//                     ENUM
//--------------------------------------------------

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_pmt
{
	char			*disp;
	char			*prompt;
	t_grp			*start_group;
	t_chk			*checker;
	void			*l_shell;
}	t_pmt;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and Initialize (pmt_init) a new t_pmt struct
 * 
 * @param disp String to be display at the begining of a prompt
 * @return t_pmt* returned structure
 */
t_pmt*	pmt_new(const char* disp, void *shell);
/**
 * @brief Inialize a t_pmt structure
 * 
 * @param pmt Struct to initialize
 * @param disp String to be display at the begining of a prompt
 * @return t_bool FALSE if an error occured
 */
t_bool	pmt_init(t_pmt* pmt, const char* disp, void *shell);

//====================== START ======================
/**
 * @brief Calling prompt for reading in the stdoutput
 * 
 * @param pmt current t_pmy structure
 * @return t_promptret: Retuen status of the prompt
 */
t_promptret pmt_start(t_pmt* pmt);

/**
 * @brief 
 * 
 * @param pmt 
 * @return t_promptret 
 */
t_promptret pmt_exec(t_pmt* pmt);

//====================== CHECK ======================
/**
 * @brief Check if the current input is valid
 * 
 * @param pmt Prompt to check
 * @return t_promptret Return status of the current command
 */
t_promptret pmt_checkinput(t_pmt *pmt);

//====================== PARSE ======================
/**
 * @brief Apply prompt when user press enter
 * 
 * @param pmt current t_pmy structure
 * @return t_bool: (FALSE if Failed)
 */
t_promptret pmt_parse(t_pmt* pmt);


//====================== CLEAR ======================
/**
 * @brief Clear a t_pmt structure and set passed var to NULL
 * 
 * @param pmt Pointer of pointer of a t_pmt structure
 */
void	pmt_clear(t_pmt **pmt);

//====================== DEBUG ======================
/**
 * @brief Print detailed info on the current prompt
 * 
 * @param pmt t_pmt to display
 */
void pmt_print(t_pmt* pmt);

#endif //PROMPT_H
