/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:35:02 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/15 13:04:59 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

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
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_READ_STDIN,
	TOK_REDIR_OUTEND,
	TOK_AND,
	TOK_OR,
	TOK_PIPE,
	TOK_OPEN_PAR,
	TOK_CLOSE_PAR,
}	t_token_type;

//--------------------------------------------------
//                   STRCUTURES
//--------------------------------------------------
typedef struct s_token
{
	char			*input;
	t_token_type	type;
	void			*l_shell;
}	t_token;

//--------------------------------------------------
//                    FUNCTIONS
//--------------------------------------------------
//====================== INIT ======================
/**
 * @brief Create and initialize (tok_init) a t_token structure
 * 
 * @param shell Referebce to the main shell structure
 * @return t_token* Newly created struct
 */
t_token	*tok_create(void *shell);
/**
 * @brief Initialize a t_token structure
 * 
 * @param token t_token to initialize
 * @param shell Referebce to the main shell structure
 * @return t_bool FALSE if fail
 */
t_bool	tok_init(t_token* token, void *shell);

//====================== PARSE======================
/**
 * @brief Parse the current token and check the following chars to defines its type
 * 
 * @param token Token to parse in
 * @param vpmt Ref to the current t_pmt struct
 * @param pos Pos of the current character in the prompt of the given t_pmt struct (Will increment it)
 * @return t_bool FALSE if failed.
 */
t_bool tok_parse(t_token *token, void *vgrp, size_t *pos);

//====================== UTIL ======================
/**
 * @brief Check if char is a controle charatcer (|, &, >, <)
 * 
 * @param c Character to chekc
 * @return t_bool TRUE if match
 */
t_bool tok_iscontrole(char c);
/**
* @brief Check if char is a sub controle charatcer (|, &)
* 
* @param c Character to chekc
* @return t_bool TRUE if match
*/
t_bool tok_issubcontrole(char c);
/**
 * @brief Check if the given charcter is a parenthesis
 * 
 * @param c Character to check
 * @return t_bool TRUE if a parentesis
 */
t_bool tok_is_par(char c);
/**
 * @brief Test if he token a redirection token (>, >>, <, <<)
 * 
 * @param token token to test
 * @return t_bool TRUE if one of the above
 */
t_bool tok_is_redir(t_token *token);

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

//====================== ERROR ======================
/**
 * @brief Check if the token is a valid token
 * 
 * @param token Token to check
 * @return t_bool TRUE if valid
 */
t_bool tok_checkvalidity(t_token* token);

//====================== DEBUG ======================
/**
 * @brief Print debug information of the t_token
 * 
 * @param token Token to print
 */
void tok_print(t_token *token);

#endif //TOKENS_H
