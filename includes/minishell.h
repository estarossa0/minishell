/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b-pearl <b-pearl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:25:48 by arraji            #+#    #+#             */
/*   Updated: 2020/12/07 17:51:23 by b-pearl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
typedef char bool;
# define true 0
# define false 1
# define D_ERROR
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include "libft.h"
# include "struct.h"
# include "parser.h"
# include "error.h"
# include "variable_expansion.h"
# include "execute.h"
# include "env_handle.h"
# include "need.h"
# include "signals_handler.h"
t_all	*g_all;
extern char **environ;
t_env		*g_env;
int			g_total_env;
int			g_shit_happened;
bool	here_we_go(t_all *all);
#endif
