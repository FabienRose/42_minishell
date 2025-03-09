/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:12:48 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/09 11:33:21 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

#include "command/command.h"
#include "tokens/token.h"
#include "builtins/builtins.h"
#include "exec/exec.h"
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
	t_cmd			*arg_cmd;
	t_token			**tokens;
	t_token			*last_token;
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

/**
 * @brief 
 * 
 * @param pmt 
 * @return t_promtret 
 */
t_promtret pmt_exec(t_pmt* pmt);

//====================== CHECKERS ======================
/**
 * @brief Check if the current reader is within quotes (single or  double)
 * 
 * @param reader t_pmt_reader to check
 * @return t_bool TRUE if within quotes
 */
t_bool pmt_isinquote(t_pmt_reader* reader);

//====================== VARS ======================
/**
 * @brief Aplly the given variable to the reader
 * 
 * @param pmt Promt to apply the variable
 * @param value Env var to get
 * @return t_bool 
 */
t_bool pmt_applyargs(t_pmt *pmt, char *value);
/**
 * @brief Get the variable in the environment and return it
 * 
 * @param pmt Prompt to chekc
 * @param pos Starting pos (Pointer to increment parse position)
 * @return char* Environmnet variable value
 */
char *pmt_parseargs(t_pmt* pmt, size_t *pos);
/**
 * @brief Called whenever a $ is detected and will apply the variable to the prompt
 * 
 * @param pmt Prompt to apply the variable to
 * @param pos Reference to the current prompt position
 * @return t_bool FALSE if failed
 */
t_bool pmt_onarg(t_pmt* pmt, size_t *pos);

//====================== LINK ======================
/**
 * @brief Will link the commands together and also check the tokens validity
 * 
 * @param pmt 
 * @return t_promtret 
 */
t_promtret pmt_link(t_pmt* pmt);

//====================== CMD ======================
/**
 * @brief Add a new command to the t_pmt and set it as active
 * 
 * @param pmt t_pmt in which the command wil be added
 * @return t_bool FASLE if failed
 */
t_bool pmt_newcmd(t_pmt* pmt);

//====================== TOKEN ======================
/**
 * @brief Add a new token the the prompt and parse it
 * 
 * @param pmt Promt to add the token in
 * @param pos Position of the begining of the token (will increment the value)
 * @return t_bool FALSE if failed
 */
t_bool pmt_addtok(t_pmt* pmt, size_t *pos);

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

//====================== DEBUG ======================
/**
 * @brief Print detailed info on the current prompt
 * 
 * @param pmt t_pmt to display
 */
void pmt_print(t_pmt* pmt);

#endif //PROMPT_H
