/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capabilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:31:34 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 08:42:38 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	init_edit_char(t_cmd *cmd)
{
	cmd->cap.insert_char.im = tgetstr("im", NULL);
	cmd->cap.insert_char.ei = tgetstr("ei", NULL);
	cmd->cap.insert_char.ic = tgetstr("ic", NULL);
	cmd->cap.insert_char.ip = tgetstr("ip", NULL);
}

void			ft_init_capabilities(t_cmd *cmd)
{
	init_edit_char(cmd);
}
