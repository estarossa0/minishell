/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:25:48 by arraji            #+#    #+#             */
/*   Updated: 2021/04/07 13:45:58 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
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
# include <termcap.h>
# include <termios.h>
# include "libft.h"
# include "struct.h"
# include "parser.h"
# include "error.h"
# include "variable_expansion.h"
# include "execute.h"
# include "env_handle.h"
# include "need.h"
# include "signals_handler.h"
# include "history.h"

t_all	*g_all;
t_bool	here_we_go(t_all *all);
#endif
