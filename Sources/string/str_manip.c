/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:45:02 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/30 09:03:40 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** prevents overflow when bypassing the 2048 command line convention
*/

static void		check_str_overflow(t_cmd *cmd)
{
	char	*place_holder;

	if (cmd->length > cmd->buff_size)
	{
		place_holder = (char *)malloc((cmd->buff_size + 100) * sizeof(char));
		if (place_holder)
		{
			memcpy(place_holder, cmd->line, cmd->length);
			free(cmd->line);
			cmd->line = place_holder;
			cmd->buff_size += 100;
		}
	}
}

/*
** add the pqssed charcater into pos (refered to by the current cursor pos)
*/

void			str_add(t_cmd *cmd, int c)
{
	int			index;

	check_str_overflow(cmd);
	index = cmd->length;
	while (index >= cmd->index)
	{
		cmd->line[index] = cmd->line[index - 1];
		index--;
	}
	cmd->line[cmd->index - 1] = c;
	cmd->index += 1;
	cmd->length += 1;
}