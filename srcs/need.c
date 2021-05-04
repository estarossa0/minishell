/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:16:26 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 16:02:33 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_saving(int savefd[2])
{
	static int	flip = 0;

	if (flip == 0)
	{
		savefd[0] = dup(0);
		savefd[1] = dup(1);
	}
	else
	{
		dup2(savefd[0], 0);
		close(savefd[0]);
		dup2(savefd[1], 1);
		close(savefd[1]);
	}
	if (flip)
		flip = 0;
	else
		flip = 1;
}

void	dup_close(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

int	find_replace(t_env *var)
{
	t_env	*curr;

	curr = g_all->env;
	while (curr)
	{
		if (!ft_strcmp(curr->key, var->key))
		{
			if (var->type == SHELL_VAR)
			{
				ft_lstdel_index((t_list **)&var,
					(void (*)(t_list *))del_env, 0);
				return (1);
			}
			var->next = curr->next;
			free(curr->key);
			free(curr->full_var);
			free(curr->value);
			*curr = *var;
			free(var);
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (0);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "pwd"))
		return (2);
	if (!ft_strcmp(cmd, "export"))
		return (3);
	if (!ft_strcmp(cmd, "env"))
		return (4);
	if (!ft_strcmp(cmd, "unset"))
		return (5);
	if (!ft_strcmp(cmd, "exit"))
		return (6);
	return (-1);
}
