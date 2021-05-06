/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 00:11:18 by arraji            #+#    #+#             */
/*   Updated: 2021/04/05 14:36:52 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	if (sig == SIGINT && g_all->pid == 0)
	{
		ft_fprintf(1, "\n" BOLD PRINT_RED PS RESET);
		g_all->exit_status = 1;
		readline(NULL, &(g_all->hist));
	}
}
