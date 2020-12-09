/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b-pearl <b-pearl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:23:09 by arraji            #+#    #+#             */
/*   Updated: 2020/12/09 00:05:53 by b-pearl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_all *all)
{
	if (g_env == NULL)
	{
		g_total_env = 0;
		g_all = all;
		init_env();
	}
	all->parser.bits = 64;
	all->parser.line = NULL;
	all->pipe = NULL;
}

void	clear(t_all *all)
{
	t_command	*curr;

	while (all->pipe)
	{
		curr = all->pipe->cmd_head;
		while (curr)
		{
			free_tab(curr->argv, ft_tablen(curr->argv));
			ft_end((void**)&(curr->full_path), (void**)&(curr->file), 1);
			while (curr->list_args)
				curr->list_args = (t_args *)ft_lstdelone((t_list *)curr->list_args, NULL);
			curr = curr->next;
		}
		all->pipe = all->pipe->next;
	}
}

int main()
{
	t_all	all;
	
	
	all.exit_status = 0;
	while (1)
	{
		signal(SIGINT, handler);
		init(&all);
		if (get_data(&all) == false || here_we_go(&all) == false || 1)
			clear(&all);
	}
}
