/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:08:06 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/26 17:46:12 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

//--------------------------------------------------
//				  LOCAL INCLUDES
//--------------------------------------------------
# include "common.h"

//--------------------------------------------------
//					  STRUCTURE
//--------------------------------------------------
typedef struct s_chk
{
	t_bool in_dq;
	t_bool in_sq;
	int		par_count;
	char	*last_msg;
}	t_chk;

//--------------------------------------------------
//					  FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and initialize a new checker strutcure
 * @brief (Generical function signature)
 * 
 * @return void* Newly created checker structure
 */
void	*chk_new(void);
/**
 * @brief Create and initialize a new checker strutcure
 * 
 * @return t_chk* Newly created checker structure
 */
t_chk	*chk_create(void);
/**
 * @brief Initialize a new checker structure
 * 
 * @param chk checker struct to initialize
 * @return t_bool FALSE if failed
 */
t_bool	chk_init(t_chk *chk);

//====================== CHECKER ======================
/**
 * @brief Check a character in the tester structure
 * 
 * @param chk Checker structure
 * @param c Character to check
 * @return t_promptret PMT_FAILED if parsing error
 */
t_promptret chk_onchar(t_chk *chk, char c);

//====================== ERROR ======================
/**
 * @brief Set last_msg "Unexpected token" for a sigle char token
 * 
 * @param chk chk in which the last message will be set.
 * @param c Char to print
 */
void chk_unexpteced_ctoken(t_chk *chk, char c);

//====================== CLEAR ======================
/**
 * @brief Clear and release a checker structure
 * @brief (Generical function signature)
 * 
 * @param chk checker structure to clear
 */
void	chk_release(void *chk);
/**
 * @brief Clear and release a checker structure
 * 
 * @param chk Pointer of pointer of a checker structure to clear
 */
void	chk_clear(t_chk **chk);

#endif //CHECKER_H
