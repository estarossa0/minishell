/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:45:02 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 10:49:41 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
**	Ensures a 100 byte buffer
**	Meaures Against overflow
*/

static void		check_str_overflow(char *str, t_cmd *cmd)
{
	size_t		len;
	char		*tmp;

	len = strlen(str);
	if (len - 50 > cmd->length)
	{
		tmp = (char *)malloc(len + 50);
		memset(tmp, '\0', len + 50);
		memcpy(tmp, cmd->line, len);
		free(cmd->line);
		cmd->line = tmp;
	}
}

void			str_add(t_cmd *cmd, int c)
{
}