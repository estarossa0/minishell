/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:37:33 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:37:50 by arraji           ###   ########.fr       */
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
# include "struct_bonus.h"
# include "parser_bonus.h"
# include "error_bonus.h"
# include "variable_expansion_bonus.h"
# include "execute_bonus.h"
# include "env_handle_bonus.h"
# include "need_bonus.h"
# include "signals_handler_bonus.h"
t_all	*g_all;
extern char **environ;
t_env		*g_env;
int			g_total_env;
pid_t		g_pid;
bool	here_we_go(t_all *all);
#endif
