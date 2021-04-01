/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_need.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:34:46 by rbougssi          #+#    #+#             */
/*   Updated: 2021/03/30 15:10:55 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		hist_init(t_hlist *head, t_hlist **end)
{
	*end =
	dlist_push_back(&g_all->hist.list, (t_hlist *)malloc(sizeof(t_hlist)));
	g_all->hist.list = *end;
	(*end)->llen = 0;
	(*end)->cmd = NULL;
	(*end)->updated = NULL;
	if (g_all->hist.head == NULL)
		g_all->hist.head = g_all->hist.end;
	while (head)
	{
		head->updated = ft_strdup(head->cmd);
		head = head->next;
	}
}

void		hist_reset(t_hlist *head, int all)
{
	struct termios	restore;

	while (head)
	{
		free(head->updated);
		head->updated = NULL;
		head->llen = ft_strlen(head->cmd);
		head = head->next;
	}
	if (all)
	{
		write(1, "\n", 1);
		tcgetattr(0, &restore);
		restore.c_lflag |= (ICANON | ECHO);
		tcsetattr(0, TCSANOW, &restore);
	}
}

t_hlist		*dlist_push_back(t_hlist **lst, t_hlist *new)
{
	t_hlist	*save;

	if (!new || !lst)
		return (NULL);
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
	}
	else
	{
		save = *lst;
		while (save->next)
			save = save->next;
		save->next = new;
		new->prev = save;
	}
	return (new);
}

void		del(int size)
{
	while (size-- > 0)
		write(1, "\b \b", 3);
}
