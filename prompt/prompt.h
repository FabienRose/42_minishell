/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:31:01 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/22 09:58:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

//--------------------------------------------------
//                     ENUM
//--------------------------------------------------
typedef enum e_promptret
{
	PMT_SUCCESS,
	PMT_FAILED,
	PMT_STOP,
	PMT_ERROR,	
}	t_promtret;

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_pmt
{
	char	*disp;
	void	*l_shell;
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

//====================== CLEAR ======================
/**
 * @brief Clear a t_pmt structure and set passed var to NULL
 * 
 * @param pmt Pointer of pointer of a t_pmt structure
 */
void	pmt_clear(t_pmt **pmt);

#endif //PROMPT_H
