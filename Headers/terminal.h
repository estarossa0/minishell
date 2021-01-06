/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:28:00 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/30 09:20:27 by ikhadem          ###   ########.fr       */
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
# include "ft_string.h"

int			init_terminal(void);
int			setup_terminal(struct termios *term);
int			unset_terminal(struct termios *term);
void		ft_init_capabilities(t_cmd *cmd);
void		insert_mode(int c, t_cmd *cmd);
void		delete_mode(t_cmd *cmd);
void		terminal_clear_screen(t_cmd *cmd);

#endif