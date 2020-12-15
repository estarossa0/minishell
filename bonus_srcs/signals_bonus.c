/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:35:21 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:36:21 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_fprintf(1, "\n" BOLD PRINT_RED PS RESET);
		g_all->exit_status = 128 + sig;
	}
	if (sig == SIGQUIT)
	{
		if (g_pid == 0)
			write(1, "\b \b\b \b", 6);
	}
}
