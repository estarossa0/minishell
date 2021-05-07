/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_need.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:22:05 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 15:05:03 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	env_sort(t_env *lst)
{
	t_env	*begin_list;
	t_env	*tmp;
	t_env	swap;

	begin_list = lst;
	while (lst != NULL)
	{
		tmp = begin_list;
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->key, tmp->next->key) > 0)
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
		ft_lstadd_back((t_list **)&head, (t_list *)new);
		lst = lst->next;
	}
	return (head);
}

t_bool	print_export(t_env *list)
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
	return (TRUE);
}

int	valid_var(t_env *var)
{
	int	index;

	index = 0;
	if (!ft_isalpha(var->key[0]) && var->key[0] != '_')
		return (0);
	while (var->key[index])
	{
		if (!ft_isalnum(var->key[index]) && var->key[index] != '_')
			return (0);
		index++;
	}
	return (1);
}
