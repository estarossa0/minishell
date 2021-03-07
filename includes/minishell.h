/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:25:48 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 16:07:29 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# define TRUE 0
# define FALSE 1
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
char	**g_environ;
t_env		*g_env;
int			g_total_env;
pid_t		g_pid;
t_bool	here_we_go(t_all *all);
#endif
