/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:11:20 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 14:57:12 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_env(t_env *env)
{
	free(env->full_var);
	free(env->key);
	free(env->value);
}

void	print_env(void)
{
	t_env	*curr;

	curr = g_all->env;
	while (curr)
	{
		if (curr->type == ENV_VAR)
			ft_fprintf(1, "%s\n", curr->full_var);
		curr = curr->next;
	}
}

t_env	*new_var(char *full_var)
{
	int		split;
	t_env	*new;

	split = 0;
	new = (t_env *)malloc(sizeof(t_env));
	new->plus = 0;
	while (full_var[split] != '=' && full_var[split])
		split++;
	if (full_var[split - 1] == '+')
		new->plus = 1;
	new->key = ft_substr(full_var, 0, split - new->plus);
	if (full_var[split] == '=')
		new->type = ENV_VAR;
	else
		new->type = SHELL_VAR;
	if (new->type == ENV_VAR)
		g_all->total_env++;
	new->value = ft_substr(full_var, split + 1,
			ft_strlen(full_var) - split);
	if (new->type == ENV_VAR)
		new->full_var = ft_strjoin(new->key, "=");
	else
		new->full_var = ft_strjoin(new->key, "");
	ft_stradd(&(new->full_var), new->value, 1);
	return (new);
}

void	init_env(void)
{
	int		index;
	t_env	*current;

	index = 0;
	while (g_all->environ[index])
	{
		current = new_var(g_all->environ[index]);
		ft_lstadd_back((t_list **)&g_all->env, (t_list *)current);
		index++;
		g_all->total_env++;
		current->type = ENV_VAR;
	}
}

char	**reverse_env(void)
{
	t_env	*curr;
	char	**env;
	int		index;

	index = 0;
	curr = g_all->env;
	env = (char **)malloc(sizeof(char *) * (g_all->total_env + 1));
	while (curr)
	{
		if (curr->type == ENV_VAR)
			env[index++] = curr->full_var;
		curr = curr->next;
	}
	env[index] = NULL;
	return (env);
}
