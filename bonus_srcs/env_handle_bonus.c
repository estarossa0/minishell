/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:33:48 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:47:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	del_env(t_env *env)
{
	free(env->full_var);
	free(env->key);
	free(env->value);
}

void	print_env(void)
{
	t_env	*curr;

	curr = g_env;
	while (curr)
	{
		ft_fprintf(1, "%s\n", curr->full_var);
		curr = curr->next;
	}
}

t_env	*new_var(char	*full_var)
{
	int		split;
	t_env	*new;

	split = 0;
	new = (t_env *)malloc(sizeof(t_env));
	(new->full_var = ft_strdup(full_var)) == NULL ? error(E_STANDARD, 1, NULL) : 1;
	while (full_var[split] != '=' && full_var[split])
		split++;
	(new->key = ft_substr(new->full_var, 0, split))  == NULL ? error(E_STANDARD, 1, NULL) : 1;
	(new->value = ft_substr(new->full_var, split + 1,
	ft_strlen(new->full_var) - split)) == NULL ? error(E_STANDARD, 1, NULL) : 1;
	return (new);
}

void	init_env()
{
	int		index;
	t_env	*current;

	index = 0;
	while(g_environ[index])
	{
		current = new_var(g_environ[index]);
		ft_lstadd_back((t_list**)&g_env, (t_list*)current);
		index++;
		g_total_env++;
	}
}

char	**reverse_env()
{
	t_env	*curr;
	char	**env;
	int		index;

	index = 0;
	curr = g_env;
	env = (char **)malloc(sizeof(char *) * (g_total_env + 1));
	env == NULL ? error(E_STANDARD, 1, NULL) : 1;
	while (curr)
	{
		env[index++] = curr->full_var;
		curr = curr->next;
	}
	env[index] = NULL;
	return (env);
}
