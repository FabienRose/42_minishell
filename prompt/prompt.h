/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:31:01 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/26 09:15:37 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

#include "command/command.h"

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
typedef struct s_pmt_reader
{
	char	*buffer;
	size_t	pos;
	size_t	size;
	t_bool	is_in_sq;
	t_bool	is_in_dq;
}	t_pmt_reader;

typedef struct s_pmt
{
	char			*disp;
	char			*prompt;
	t_pmt_reader	*reader;
	t_cmd			**cmds;
	t_cmd			*active_cmd;
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
/**
 * @brief Create and Initialize (pmt_reader_init) a new t_pmt_reader struct
 * 
 * @return t_pmt_reader* returned structure
 */
t_pmt_reader* pmt_reader_new();
/**
 * @brief Inialize a t_pmt_reader structure
 * 
 * @param reader Struct to initialize
 * @return t_bool FALSE if an error occured
 */
t_bool pmt_reader_init(t_pmt_reader *reader);

//====================== START ======================
/**
 * @brief Calling prompt for reading in the stdoutput
 * 
 * @param pmt current t_pmy structure
 * @return t_promtret: Retuen status of the prompt
 */
t_promtret pmt_start(t_pmt* pmt);

//====================== CHECKERS ======================
/**
 * @brief Check if char is a controle charatcer (|, &, >, <)
 * 
 * @param c Character to chekc
 * @return t_bool TRUE if match
 */
t_bool pmt_iscontrole(char c);

/**
 * @brief Check if the current reader is within quotes (single or  double)
 * 
 * @param reader t_pmt_reader to check
 * @return t_bool TRUE if within quotes
 */
t_bool pmt_isinquote(t_pmt_reader* reader);

//====================== PARSE ======================
/**
 * @brief Apply prompt when user press enter
 * 
 * @param pmt current t_pmy structure
 * @return t_bool: (FALSE if Failed)
 */
t_bool pmt_parse(t_pmt* pmt);

//====================== READER ======================
/**
 * @brief Add a char to the current reader buffer (cann call pmt_reader_extendbuffer)
 * 
 * @param reader t_pmt_reader of the current prompt
 * @param c character to add
 * @return t_bool Return FALSE if malloc fail (called by pmt_reader_extendbuffer)
 */
t_bool pmt_reader_addchar(t_pmt_reader* reader, char c);
/**
 * @brief Resize the given reader buffer
 * 
 * @param reader t_pmt_reader of the current prompt
 * @return t_bool Return FALSE if malloc fail (called by pmt_reader_extendbuffer)
 */
t_bool pmt_reader_extendbuffer(t_pmt_reader* reader);
/**
 * @brief Extract the current string in the reader buffer and reset the reader
 * 
 * @param reader t_pmt_reader to extract from.
 * @return char* extracted string
 */
char *pmt_reader_extract(t_pmt_reader *reader);

//====================== CLEAR ======================
/**
 * @brief Clear a t_pmt structure and set passed var to NULL
 * 
 * @param pmt Pointer of pointer of a t_pmt structure
 */
void	pmt_clear(t_pmt **pmt);
/**
 * @brief Clear a t_pmt_reader structure
 * 
 * @param reader Pointer of a t_pmt_reader structure
 */
void	pmt_reader_clear(t_pmt_reader **reader);

#endif //PROMPT_H
