/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:23:09 by arraji            #+#    #+#             */
/*   Updated: 2020/12/14 23:50:50 by arraji           ###   ########.fr       */
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
	g_pid = 0;
	all->parser.bits = 64;
	ft_end((void **)&(all->parser.line), NULL, 1);
	all->pipe = NULL;
}

void	clear(t_all *all)
{
	t_command	*curr;
	t_pipeline	*currp;
	void		*save;
	while (all->pipe)
	{
		curr = all->pipe->cmd_head;
		while (curr)
		{
			free_tab(curr->argv, ft_tablen(curr->argv));
			ft_end((void**)&(curr->full_path), (void**)&(curr->file), 1);
			while (curr->list_args)
				curr->list_args = (t_args *)ft_lstdelone((t_list *)curr->list_args, NULL);
			save = (void *)curr;
			curr = curr->next;
			free(save);
		}
		save = (void *)all->pipe;
		all->pipe = all->pipe->next;
		free(save);
	}
}

int main()
{
	t_all	all;
	
	all.exit_status = 0;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	all.parser.line = NULL;
	while (1)
	{
		init(&all);
		if (get_data(&all) == false || here_we_go(&all) == false || 1)
			clear(&all);
	}
}
