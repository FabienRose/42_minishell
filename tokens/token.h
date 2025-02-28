/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:32:21 by kgauthie          #+#    #+#             */
/*   Updated: 2025/02/28 10:28:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

//--------------------------------------------------
//                 LOCAL INCLUDES
//--------------------------------------------------
#include "common.h"

//--------------------------------------------------
//                     ENUMS
//--------------------------------------------------
typedef enum e_token_type
{
	TOK_NONE,
	TOK_REDIR_LEFT,
	TOK_REDIR_RIGHT,
	TOK_CHECKER_LEFT,
	TOK_CHECKER_RIGHT,
	TOK_AND,
	TOK_OR,
	TOK_PIPE,
}	t_token_type;

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_token
{
	char			*input;
	t_token_type	type;
}	t_token;


//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and initialize (tok_init) a t_token structure
 * 
 * @return t_token* Newly created struct
 */
t_token	*tok_create();/**
* @brief Create and initialize (tok_init) a t_token structure
* 
* @return t_token* Newly created struct
*/
void	*tok_new();
/**
 * @brief Initialize a t_token structure
 * 
 * @param token t_token to initialize
 * @return t_bool FALSE if fail
 */
t_bool	tok_init(t_token* token);

//====================== PARSE======================
/**
 * @brief Parse the current token and check the following chars to defines its type
 * 
 * @param token Token to parse in
 * @param vpmt Ref to the current t_pmt struct
 * @param pos Pos of the current character in the prompt of the given t_pmt struct (Will increment it)
 * @return t_bool FALSE if failed.
 */
t_bool tok_parse(t_token *token, void *vpmt, size_t *pos);

//====================== UTIL ======================
/**
 * @brief Check if char is a controle charatcer (|, &, >, <)
 * 
 * @param c Character to chekc
 * @return t_bool TRUE if match
 */
t_bool tok_iscontrole(char c);

//====================== CLEAR ======================
/**
 * @brief Clear a t_token struct and free the struct from its suffering
 * 
 * @param token Pointer of pointer of the t_token structure to clear
 */
void	tok_clear(t_token **token);
/**
 * @brief libft compatible version of cmd_clear;
 * 
 * @param token Pointer of pointer of the t_token structure to clear
 */
void	tok_release(void *token);

//====================== DEBUG ======================
/**
 * @brief Print debug information of the t_token
 * 
 * @param token Token to print
 */
void tok_print(t_token *token);

#endif //TOKEN_H
