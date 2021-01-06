/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:12:18 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/05 12:32:51 by ikhadem          ###   ########.fr       */
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
	if (!(cmd->line = (char *)malloc(CMD_MAX_LEN * sizeof (char))))
		return (FALSE);
	cmd->index = 1;
	cmd->length = 0;
	cmd->buff_size = CMD_MAX_LEN;
	memset(cmd->line, '\0', cmd->buff_size);
	return (TRUE);
}

void input_manip(t_cmd *command)
{
	int			c;

	c = 0;
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
	ft_init_capabilities(&command);
	while (1)
		input_manip(&command);
	if (!unset_terminal(&term))
		exit(-1);
	return 0;
}