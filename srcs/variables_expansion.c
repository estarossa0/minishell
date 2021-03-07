/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:48:41 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:29:03 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(char *var_name)
{
	t_env	*curr;

	curr = g_env;
	if (ft_strcmp(var_name, "?") == 0)
		return (ft_itoa(g_all->exit_status));
	while (curr)
	{
		if (ft_strcmp(var_name, curr->key) == 0)
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}

void	variable_expansion(char *line, int *index, t_command *current)
{
	char	*var_name;
	int		save;

	(*index)++;
	save = *index;
	while (ft_isalnum(line[*index + 1]) || line[*index + 1] == '_')
		(*index)++;
	var_name = ft_substr(line, save, (*index) - save + 1);
	if (var_name)
		add_word(&current->list_args, var_name, 1);
}
