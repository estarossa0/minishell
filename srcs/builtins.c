/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 06:13:12 by arraji            #+#    #+#             */
/*   Updated: 2020/12/14 14:02:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo_print(char **str, int i, int newline)
{
	int		j;
	while (str[i] && str[i][0] == '-')
	{
		if (str[i][1] == 'n')
		{
			j = 2;
			while (str[i][j] && str[i][j] == 'n')
				j++;
			if (str[i][j] == '\0')
				newline = 1;
			else
				break ;
		}
		else
			break ;
		i++;
	}
	while (str[i] != NULL)
	{
		ft_fprintf(1, "%s", str[i]);
		(str[i + 1] != NULL) ? write(1, " ", 1) : 1;
		i++;
	}
	return (newline);
}

static	bool	b_echo(t_command *cmd)
{
	int		index;
	int		save;

	save = 0;
	index = 1;
	save = ft_echo_print(cmd->argv, 1, 0);
	save ? 1 : write(1, "\n", 1);
	g_all->exit_status = 0;
	return (true);
}

static	bool	b_cd(t_command *cmd)
{
	int len;
	char	*home;
	bool	check;

	len = ft_tablen(cmd->argv);
	check = true;
	if	(len == 1)
	{
		home = get_var_value("HOME");
		if (home)
			check = (chdir(home) == -1) ? error(E_CD, 1, home) : true;
		else
			check = error(E_CD_HOME, 1, NULL);
	}
	else if (chdir(cmd->argv[1]) == -1)
		check = error(E_CD, 1, cmd->argv[1]);
	change_variables(g_all->pwd, check);
	return (check);
}

static	bool	b_pwd(t_command *cmd)
{
	if (ft_tablen(cmd->argv) != 1)
		return (error(E_ARGS, 1, cmd->cmd_name));
	ft_fprintf(1, "%s\n", g_all->pwd);
	return (true);
}


static	bool	b_export(t_command *cmd)
{
	int		index;
	t_env	*curr;
	bool	check;

	check = true;
	index = 0;
	if (ft_tablen(cmd->argv) == 1)
		print_export(g_env);
	else
	{
		while (cmd->argv[++index])
		{
			curr = new_var(cmd->argv[index]);
			if (ft_strlen(curr->key) == 0 || !valid_var(curr))
			{
				check = error(E_NOT_VAL, 1, curr->full_var);
				ft_lstdel_index((t_list**)&curr,
				(void (*)(t_list *))del_env, 0);
				continue ;
			}
			if (find_replace(curr))
				continue ;
			ft_lstadd_back((t_list **)&g_env, (void *)curr);
		}
	}
	return (check);
}

static	bool	b_env(t_command *cmd)
{
	if (ft_tablen(cmd->argv) != 1)
		return (error(E_ARGS, 1, cmd->cmd_name));
	print_env();
	return (true);
}

static	bool	b_unset(t_command *cmd)
{
	int		index;
	int		jndex;
	t_env	*curr;

	jndex = 0;
	curr = g_env;
	while (curr)
	{
		index = 0;
		while (cmd->argv[++index])
			if (!ft_strcmp(cmd->argv[index], curr->key))
			{
				ft_lstdel_index((t_list**)&g_env, (void (*)(t_list *))del_env, jndex);
				return (true);
			}
		jndex++;
		curr = curr->next;
	}
	return (true);
}

static	bool	b_exit(t_command *cmd)
{
	long long		index;

	write(2, "exit\n", 5);
	cmd->argv[1] == NULL ? exit(0) : 1;
	index = (cmd->argv[1][0] == '-') || (cmd->argv[1][0] == '+') ? 1 : 0;
	if (!ft_isdigit(cmd->argv[1][index]))
		exit(error(E_EXIT_ARG, 255, cmd->argv[1]));
	if (ft_tablen(cmd->argv) > 2)
		return (error(E_ARGS, 1, cmd->cmd_name));
	index = ft_atol(cmd->argv[1]);
	if (cmd->argv[1] && ((index < 0 && cmd->argv[1][0] != '-')
	|| (index >= 0 && cmd->argv[1][0] == '-')))
		error(E_EXIT_ARG, 2, cmd->argv[1]);
	exit(index);
	return (true);
}

bool	exec_builthin(t_command *cmd, int builthin)
{
	bool	(*builthin_functions[7])(t_command *cmd) = {b_echo, b_cd, b_pwd, b_export, b_env, b_unset, b_exit};
	bool	check;

	check = builthin_functions[builthin](cmd);
	g_all->exit_status = check == true ? 0 : g_all->exit_status;
	if (!cmd->simple)
		exit(g_all->exit_status);
	return (check);
}
