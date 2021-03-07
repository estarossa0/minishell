/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_need.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:22:05 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:47:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		cmp(char *a, char *b)
{
	int	index;

	index = 0;
	while (a[index])
	{
		a[index] = ft_toupper(a[index]);
		index++;
	}
	index = 0;
	while (b[index])
	{
		b[index] = ft_toupper(b[index]);
		index++;
	}
	index = ft_strcmp(a, b);
	free(a);
	free(b);
	return (index);
}

static	void	env_sort(t_env *lst)
{
	t_env	*begin_list;
	t_env	*tmp;
	t_env	swap;
	int		max[2];

	begin_list = lst;
	max[0] = ft_tablen(g_environ) + 1;
	while (lst != NULL && --max[0])
	{
		tmp = begin_list;
		max[1] = max[0] + 1;
		while (tmp->next != NULL && --max[1] - 1)
		{
			if (cmp(ft_strdup(tmp->key), ft_strdup(tmp->next->key)) > 0)
			{
				swap = *tmp;
				*tmp = *tmp->next;
				tmp->next = swap.next;
				swap.next = tmp->next->next;
				*tmp->next = swap;
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

static	t_env	*env_copy(t_env *lst)
{
	t_env	*new;
	int		check;
	t_env	*head;

	check = 0;
	head = NULL;
	while (lst)
	{
		new = (t_env *)malloc(sizeof(t_env));
		*new = *lst;
		new->next = NULL;
		ft_lstadd_back((t_list**)&head, (t_list*)new);
		lst = lst->next;
	}
	return (head);
}

void			print_export(t_env *list)
{
	t_env	*new;
	t_env	*tmp;

	new = env_copy(list);
	env_sort(new);
	while (new)
	{
		write(1, "declare -x ", 11);
		ft_fprintf(1, "%s", new->key);
		if (new->type == ENV_VAR)
			ft_fprintf(1, "=\"%s\" ", new->value);
		write(1, "\n", 1);
		tmp = new;
		new = new->next;
		free(tmp);
	}
}
