/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups_reader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:06:53 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 12:35:21 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPS_READER_H
# define GROUPS_READER_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_grp_reader
{
	char	*buffer;
	size_t	pos;
	size_t	size;
	t_bool	is_in_sq;
	t_bool	is_in_dq;
	size_t	par_count;
	void	*l_shell;
}	t_grp_reader;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and Intialize a group reader structure
 * 
 * @param shell Referebce to the main shell structure
 * @return t_grp_reader* Newly created group reader 
 */
t_grp_reader *grp_read_create(void *shell);
/**
 * @brief Initialize a group reader structure
 * 
 * @param grp_reader Group reader to initialize
 * @param shell Referebce to the main shell structure
 * @return t_bool FALSE if failed
 */
t_bool grp_read_init(t_grp_reader *grp_reader, void *shell);


//====================== CHECKERS ======================
/**
 * @brief Check if the current reader is within quotes (single or  double)
 * 
 * @param reader t_grp_reader to check
 * @return t_bool TRUE if within quotes
 */
t_bool grp_isinquote(t_grp_reader* reader);
/**
 * @brief Check if a token can be applied
 * 
 * @param reader Reference to teh current reader
 * @return t_bool TRUE if can apply
 */
t_bool grp_canapply(t_grp_reader* reader);

//====================== MANAGE ======================

/**
 * @brief Add a char to the current reader buffer (cann call grp_read_extendbuffer)
 * 
 * @param reader t_grp_reader of the current prompt
 * @param c character to add
 * @return t_bool Return FALSE if malloc fail (called by grp_read_extendbuffer)
 */
t_promptret grp_read_addchar(t_grp_reader* reader, char c);
/**
 * @brief Resize the given reader buffer
 * 
 * @param reader t_grp_reader of the current prompt
 * @return t_bool Return FALSE if malloc fail (called by grp_read_extendbuffer)
 */
t_bool grp_read_extendbuffer(t_grp_reader* reader);
/**
 * @brief Extract the current string in the reader buffer and reset the reader
 * 
 * @param reader t_grp_reader to extract from.
 * @return char* extracted string
 */
char *grp_read_extract(t_grp_reader *reader);

//====================== CLEAR ======================
/**
 * @brief Generical function to free a group reader structure (Calling grp_clear)
 * 
 * @param grp_reader Group reader to free
 */
void grp_read_release(void *grp_reader);
/**
 * @brief Clear and release a group reader structure
 * 
 * @param grp_reader Pointer of the pointer to the groupe reader structure 
 */
void grp_read_clear(t_grp_reader **grp_reader);

#endif //GROUPS_READER_H
