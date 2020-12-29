/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capabilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 08:31:34 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 09:37:49 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void		init_edit_char(t_cmd *cmd)
{
	cmd->cap.insert_char.im = tgetstr("im", NULL);
	cmd->cap.insert_char.ei = tgetstr("ei", NULL);
	cmd->cap.insert_char.ic = tgetstr("ic", NULL);
	cmd->cap.insert_char.ip = tgetstr("ip", NULL);
}

static void		init_delete_char(t_cmd *cmd)
{
	cmd->cap.delete_char.dc = tgetstr("dc", NULL);
	cmd->cap.delete_char.dm = tgetstr("dm", NULL);
	cmd->cap.delete_char.ed = tgetstr("ed", NULL);
}

void			ft_init_capabilities(t_cmd *cmd)
{
	init_edit_char(cmd);
	init_delete_char(cmd);
}
