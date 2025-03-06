/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:11:15 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/06 09:48:20 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//--------------------------------------------------
//                  C INCLUDES
//--------------------------------------------------
# include "stdlib.h"
# include "unistd.h"


//--------------------------------------------------
//                   COMMON
//--------------------------------------------------
//====================== BOOLEAN ======================
typedef unsigned char	t_bool;
# define TRUE 1
# define FALSE 0

//====================== PRINT ======================
# define FONT_NRM			"\x1B[0m"
# define FONT_RED 			"\x1B[31m"
# define FONT_GRN 			"\x1B[32m"
# define FONT_YEL 			"\x1B[33m"
# define FONT_BLU 			"\x1B[34m"
# define FONT_MAG 			"\x1B[35m"
# define FONT_CYN 			"\x1B[36m"
# define FONT_WHT 			"\x1B[37m"
# define FONT_BOLD			"\033[1m"	 	 
# define FONT_UNDERLINE		"\033[4m"	 
# define FONT_NO_UNDERLINE	"\033[24m"	 


//--------------------------------------------------
//                   CHECKERS
//--------------------------------------------------
t_bool	ft_isalpha(int c);
t_bool	ft_isdigit(int c);
t_bool	ft_isalnum(int c);
t_bool	ft_isascii(int c);
t_bool	ft_isprint(int c);
/**
 * @brief Same as isspace(3)
 * @note CHeck man of isspace(3)
 * 
 * @param c Character to check
 * @return t_bool TRUE if is space
 */
t_bool	ft_isspace(int c);

//--------------------------------------------------
//                  CONVERTIONS
//--------------------------------------------------
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

//--------------------------------------------------
//                  	IO
//--------------------------------------------------
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//--------------------------------------------------
//                     LISTS
//--------------------------------------------------
	//====================== STRUCTURS ======================
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

	//====================== FUNCTIONS ======================
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//--------------------------------------------------
//                     MEMORY
//--------------------------------------------------
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief Realloc memory and copy data the newly create pointer
 * @warning Old memory will be freed any other var pointing to ptr will no longer have access
 * 
 * @param ptr Pointer of the pointer to realloc
 * @param old_len Current size in Byte of the memory
 * @param new_len New size in Byte of the memory
 * @return t_bool FALSE if Failed
 */
t_bool	ft_realloc(void **ptr, size_t old_len, size_t new_len);
/**
 * @brief Realloc memory and copy data the newly create pointer (size * QUANTITY)
 * @warning Old memory will be freed any other var pointing to ptr will no longer have access
 * 
 * @param ptr Pointer of the pointer to realloc
 * @param old_len Current in QUANTITY of the memory
 * @param new_len New size in QUANTITY of the memory
 * @param data_size Size of one type (QUANTITY)
 * @return t_bool FALSE if Failed
 */
t_bool ft_realloc_s(void **ptr, size_t old_len, size_t new_len, size_t data_size);
/**
 * @brief Realloc memory and copy data the newly double array
 * @warning Old memory will be freed any other var pointing to ptr will no longer have access
 * 
 * @param ptr Pointer of the pointer to realloc
 * @param old_len Current in QUANTITY of the memory
 * @param new_len New size in QUANTITY of the memory
 * @return t_bool 
 */
t_bool ft_realloc_da(void ***ptr, size_t old_len, size_t new_len);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

//--------------------------------------------------
//                     ARRAY
//--------------------------------------------------
	//--------------------- Push ---------------------
/**
 * @brief Add and extend memory a the end of the array
 * @warning Old memory will be freed any other var pointing to ptr will no longer have access
 * 
 * @param arr Pointer of pointer of the array
 * @param size Size in Byte of the struct to be added;
 * @return void *: location of the newly created data;
 */
void *ft_arraypush(void **arr, size_t size);
/**
 * @brief Add and extend memory a the end of the double array
 * @warning Old memory will be freed any other var pointing to ptr will no longer have access
 * 
 * @param arr Pointer of pointer of the double array
 * @param ndata Pointer of the newly added structure
 * @return t_bool FALSE if failed
 */
t_bool ft_arraypush_d(void ***arr, void *ndata);
/**
 * @brief Add and extend memory a the end of the double array
 * @warning Old memory will be freed any other var pointing to ptr will no longer have access
 * 
 * @param arr Pointer of pointer of the double array
 * @param create Function called to create the new data
 * @param del Function to free newly allocated memory in case of fail
 * @return t_bool FALSE if failed
 */
t_bool ft_arraypush_df(void ***arr, void *(*create)(void), void(*del)(void *));

	//--------------------- Pop ---------------------
/**
 * @brief Remove the first element of the array and risize this latter
 * 
 * @param arr Pointer to the array to resize
 * @return void* Pointer to of the first element (Extracted);
 */
void *ft_arraypopfront_d(void ***arr);

	//--------------------- Len ---------------------
/**
 * @brief Get the size of the array
 * 
 * @param arr Array to check
 * @param size Size in Byte of the struct to count
 * @return size_t  Size of the given array
 */
size_t	ft_arraylen(void *arr, size_t size);

/**
 * @brief Get the size of the array of array
 * 
 * @param arr Double array to check
 * @return size_t  Size of the given array
 */
size_t	ft_arraylen_d(void **arr);

	//--------------------- Free ---------------------
/**
 * @brief Free and set to null a given array
 * 
 * @param arr Array to free
 */
void ft_arrayfree(void **arr);
/**
 * @brief Free a double array all component arr free using custom function
 * 
 * @param arr Pointer of the double array to free
 * @param del Function used to delete the components
 */
void ft_arrayfree_d(void ***arr, void(*del)(void *));


//--------------------------------------------------
//                    STRINGS
//--------------------------------------------------
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src);
/**
 * @brief Add charecter to a given string
 * @warning Realloc is called the previous str will be freed
 * 
 * @param str Pointer of the string pointer
 * @param c Character to add
 * @return t_bool FALSE if failed
 */
t_bool	ft_strpush(char **str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief Merge str1, str2, str3 (in order) with bstr
 * 
 * @param bstr Pointer of string, which will be realloc and merged with the other str
 * @param str1 [NULLABLE] Str to add
 * @param str2 [NULLABLE] Str to add
 * @param str3 [NULLABLE] Str to add
 * @return t_bool FALSE if failed
 */
t_bool	ft_strmerge(char **bstr, const char *str1, const char *str2, const char *str3);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
/**
 * @brief Find the first occurence of the specified char
 * 
 * @param s String to search in
 * @param c Caracter to find
 * @return char* Pointer to the char (NULL if not found)
 */
char	*ft_strfrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
/**
 * @brief Release an array of strings
 * 
 * @param arr Pointer of the array
 */
void	ft_split_release(char ***arr);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif