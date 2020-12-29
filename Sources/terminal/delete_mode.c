/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:35:24 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 09:39:56 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void		delete_mode(t_cmd *cmd)
{
	tputs(cmd->cap.delete_char.dm, 1, ft_putchar);
	tputs(cmd->cap.delete_char.dc, 1, ft_putchar);
	tputs(cmd->cap.delete_char.ed, 1, ft_putchar);
}