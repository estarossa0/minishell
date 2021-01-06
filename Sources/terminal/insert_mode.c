/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:16:48 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/05 12:50:28 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void		terminal_putchar(int c, t_capability cap)
{
	tputs(cap.insert_char.ic, 1, ft_putchar);
	ft_putchar(c);
	tputs(cap.insert_char.ip, 1, ft_putchar);
}

static void		terminal_putstr(char *str, t_capability cap)
{
	int		i;
	int		width;

	i = 0;
	width = tgetnum("co");
	while (i < strlen(str))
	{
		tputs(cap.insert_char.im, 1, ft_putchar);
		terminal_putchar(str[i], cap);
		tputs(cap.insert_char.ei, 1, ft_putchar);
		if (i % width == 0 && i != 0)
		{
			tputs(cap.cursor.dw, 1, ft_putchar);
			tputs(cap.cursor.cr, 1, ft_putchar);
		}
		i++;
	}
}

void			insert_mode(int c, t_cmd *cmd)
{
	str_add(cmd, c);
	terminal_clear_screen(cmd);
	terminal_putstr(cmd->line, cmd->cap);
}