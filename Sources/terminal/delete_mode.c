/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:35:24 by ikhadem           #+#    #+#             */
/*   Updated: 2021/01/05 12:10:43 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void		terminal_clear_screen(t_cmd *cmd)
{
	int		index;

	index = 0;
	tputs(cmd->cap.delete_char.dm, 1, ft_putchar);
	while (index < cmd->length)
	{
		tputs(cmd->cap.cursor.le, 1, ft_putchar);
		tputs(cmd->cap.delete_char.dc, 1, ft_putchar);
		index++;
	}
	tputs(cmd->cap.delete_char.ed, 1, ft_putchar);
}

void		delete_mode(t_cmd *cmd)
{
}