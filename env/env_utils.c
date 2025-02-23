 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 23/02/2025 10:31:51 by fmixtur           #+#    #+#             */
/*   Updated: 23/02/2025 10:31:51 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

extern char	**environ;

t_bool  copy_environ(t_shell *minishell)
{
    int     i;
    int     size;

    size = 0;
    while (environ[size] != NULL)
        size++;
    
    minishell->environement = malloc((size + 1) * sizeof(char *));
    if (!minishell->environement)
        return (FALSE);

    i = 0;
    while (i < size)
    {
        minishell->environement[i] = strdup(environ[i]);
        if (!minishell->environement[i])
        {
            while (i-- > 0)
                free(minishell->environement[i]);
            free(minishell->environement);
            return (FALSE);
        }
        i++;
    }
    minishell->environement[size] = NULL;
    environ = minishell->environement;
    return (TRUE);
}