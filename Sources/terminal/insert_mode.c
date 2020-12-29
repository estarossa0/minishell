/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:16:48 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 09:23:04 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void			insert_mode(int c, t_cmd *cmd)
{
	tputs(cmd->cap.insert_char.im, 1, ft_putchar);
	tputs(cmd->cap.insert_char.ic, 1, ft_putchar);
	ft_putchar(c);
	tputs(cmd->cap.insert_char.ip, 1, ft_putchar);
	tputs(cmd->cap.insert_char.ei, 1, ft_putchar);
}