/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:28:00 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 09:21:42 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/errno.h>
# include <ncurses.h>
# include <term.h>
# include "ft_io.h"
# include "ft_defines.h"

int			init_terminal(void);
int			setup_terminal(struct termios *term);
int			unset_terminal(struct termios *term);
void		ft_init_capabilities(t_cmd *cmd);
void		insert_mode(int c, t_cmd *cmd);

#endif