/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 06:13:12 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 14:41:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_bool	b_env(t_command *cmd)
{
	if (ft_tablen(cmd->argv) != 1)
		return (error(E_ARGS, 1, cmd->cmd_name));
	print_env();
	return (TRUE);
}

static	t_bool	b_unset(t_command *cmd)
{
	int		index;
	int		jndex;
	t_env	*curr;

	index = 0;
	while (cmd->argv[++index])
	{
		jndex = 0;
		curr = g_all->env;
		while (curr)
		{
			if (!ft_strcmp(cmd->argv[index], curr->key))
			{
				ft_lstdel_index((t_list **)&g_all->env,
					(void (*)(t_list *))del_env, jndex);
				break ;
			}
			jndex++;
			curr = curr->next;
		}
	}
	return (TRUE);
}

static	t_bool	b_exit(t_command *cmd)
{
	long long		index;

	write(2, "exit\n", 5);
	index = 0;
	if (cmd->argv[1] == NULL)
		exit(g_all->exit_status);
	if (cmd->argv[1][0] == '-' || cmd->argv[1][0] == '+')
		index = 1;
	while (cmd->argv[1] && cmd->argv[1][index])
		if (!ft_isdigit(cmd->argv[1][index++]))
			exit(error(E_EXIT_ARG, 255, cmd->argv[1]));
	if (ft_tablen(cmd->argv) > 2)
		return (error(E_ARGS, 1, cmd->cmd_name));
	index = ft_atol(cmd->argv[1]);
	if (cmd->argv[1] && ((index < 0 && cmd->argv[1][0] != '-')
		|| (index >= 0 && cmd->argv[1][0] == '-')))
		error(E_EXIT_ARG, 2, cmd->argv[1]);
	exit(index);
	return (TRUE);
}

t_bool	exec_builthin(t_command *cmd, int builthin)
{
	t_bool	(*builthin_functions[7])(t_command *cmd);
	t_bool	check;

	builthin_functions[0] = b_echo;
	builthin_functions[1] = b_cd;
	builthin_functions[2] = b_pwd;
	builthin_functions[3] = b_export;
	builthin_functions[4] = b_env;
	builthin_functions[5] = b_unset;
	builthin_functions[6] = b_exit;
	check = builthin_functions[builthin](cmd);
	if (check == TRUE)
		g_all->exit_status = 0;
	if (!cmd->simple)
		exit(g_all->exit_status);
	return (check);
}
