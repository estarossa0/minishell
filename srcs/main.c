/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:23:09 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 15:15:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_all *all)
{
	static int	init = 0;

	if (!init)
	{
		g_all->total_env = 0;
		init_env();
		change_variables(NULL, -1);
		g_all->hist.end = NULL;
		g_all->hist.list = NULL;
		g_all->hist.head = NULL;
		init = 1;
	}
	g_all->pid = 0;
	all->parser.bits = 64;
	ft_end((void **)&(all->parser.line), NULL, 1);
	all->pipe = NULL;
}

void	clear(t_all *all)
{
	t_command	*curr;
	void		*save;

	while (all->pipe)
	{
		curr = all->pipe->cmd_head;
		while (curr)
		{
			free_tab(curr->argv, ft_tablen(curr->argv));
			ft_end((void **)&(curr->full_path), (void **)&(curr->file), 1);
			while (curr->list_args)
				curr->list_args
					= (t_args *)ft_lstdelone((t_list *)curr->list_args, NULL);
			while (curr->all_files)
				curr->all_files
					= (t_files *)ft_lstdelone((t_list *)curr->all_files, NULL);
			save = (void *)curr;
			curr = curr->next;
			free(save);
		}
		save = (void *)all->pipe;
		all->pipe = all->pipe->next;
		free(save);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_all	all;
	int		on;

	(void)argc;
	(void)argv;
	g_all = &all;
	g_all->environ = env;
	g_all->env = NULL;
	all.exit_status = 0;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	all.parser.line = NULL;
	on = 1;
	while (on)
	{
		if (!isatty(0))
			on = 0;
		init(&all);
		if (get_data(&all) == FALSE || here_we_go(&all) == FALSE || 1)
			clear(&all);
	}
}
