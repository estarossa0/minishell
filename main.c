/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:12:18 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 09:04:05 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <termios.h>
#include "termcaps.h"
#include "ft_defines.h"

struct termios term;

void input_manip()
{
	t_cmd		command;
	int			c;

	c = 0;
	ft_init_capabilities(&command);
	read(STDIN_FILENO, &c, 1);
	if (isprint(c))
		insert_mode(c, command);
}

int		main(int argc, char **argv, char **env)
{
	if (!init_terminal())
		exit(-1);
	if (!setup_terminal(&term))
		exit(-1);
	while (1)
		input_manip();
	if (!unset_terminal(&term))
		exit(-1);
	return 0;
}