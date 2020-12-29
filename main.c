/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:12:18 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 10:14:12 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <termios.h>
#include <string.h>
#include "termcaps.h"
#include "ft_defines.h"

struct termios term;

int		ft_init_command(t_cmd *cmd)
{
	if (!(cmd->line = (char *)malloc(MIN_LEN * sizeof (char))))
		return (FALSE);
	cmd->index = 0;
	cmd->length = 0;
	memset(cmd->line, '\0', MIN_LEN);
	return (TRUE);
}

void input_manip(t_cmd *command)
{
	int			c;

	c = 0;
	ft_init_command(command);
	read(STDIN_FILENO, &c, 1);
	if (isprint(c))
		insert_mode(c, command);
	if (c == K_RETURN)
		delete_mode(command);
}

int		main(int argc, char **argv, char **env)
{
	t_cmd		command;
	if (!init_terminal())
		exit(-1);
	if (!setup_terminal(&term))
		exit(-1);
	if (!ft_init_command(&command))
		exit(-1);
	while (1)
		input_manip(&command);
	if (!unset_terminal(&term))
		exit(-1);
	return 0;
}