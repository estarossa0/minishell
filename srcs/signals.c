/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 00:11:18 by arraji            #+#    #+#             */
/*   Updated: 2020/12/14 23:53:17 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	if (sig == SIGINT && g_pid == 0)
	{
		ft_fprintf(1, "\n" BOLD PRINT_RED PS RESET);
		g_all->exit_status = 128 + sig;
		get_next_line(-5, NULL);
	}
	if (sig == SIGQUIT)
	{
		if (g_pid == 0)
			write(1, "\b \b\b \b", 6);
	}
}
