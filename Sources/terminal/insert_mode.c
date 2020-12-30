/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:16:48 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/30 09:14:37 by ikhadem          ###   ########.fr       */
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

	i = 0;
	tputs(cap.insert_char.im, 1, ft_putchar);
	while (i < strlen(str))
	{
		terminal_putchar(str[i], cap);
		i++;
	}
	tputs(cap.insert_char.ei, 1, ft_putchar);
}

void			insert_mode(int c, t_cmd *cmd)
{
	str_add(cmd, c);
	terminal_putstr(cmd->line, cmd->cap);
}