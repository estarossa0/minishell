/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 06:13:12 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_echo_print(char **str, int i, int newline)
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

static	t_bool	b_echo(t_command *cmd)
{
	int		index;
	int		save;

	save = 0;
	index = 1;
	save = ft_echo_print(cmd->argv, 1, 0);
	save ? 1 : write(1, "\n", 1);
	g_all->exit_status = 0;
	return (TRUE);
}

static	t_bool	b_cd(t_command *cmd)
{
	int		len;
	char	*home;
	t_bool	check;

	len = ft_tablen(cmd->argv);
	check = TRUE;
	if (len == 1)
	{
		home = get_var_value("HOME");
		if (home)
			check = (chdir(home) == -1) ? error(E_CD, 1, home) : TRUE;
		else
			check = error(E_CD_HOME, 1, NULL);
	}
	else if (chdir(cmd->argv[1]) == -1)
		check = error(E_CD, 1, cmd->argv[1]);
	change_variables(g_all->pwd, check);
	return (check);
}

static	t_bool	b_pwd(t_command *cmd)
{
	if (ft_tablen(cmd->argv) != 1)
		return (error(E_ARGS, 1, cmd->cmd_name));
	ft_fprintf(1, "%s\n", g_all->pwd);
	return (TRUE);
}

static	t_bool	b_export(t_command *cmd)
{
	int		index;
	t_env	*curr;
	t_bool	check;

	check = TRUE;
	index = 0;
	if (ft_tablen(cmd->argv) == 1)
		print_export(g_env);
	else
	{
		while (cmd->argv[++index])
		{
			curr = new_var(cmd->argv[index]);
			if (ft_strlen(curr->key) == 0)
			{
				check = error(E_NOT_VAL, 1, curr->full_var);
				free(curr);
				continue ;
			}
			if (find_replace(curr))
				continue ;
			ft_lstadd_back((t_list **)&g_env, (void *)curr);
		}
	}
	return (check);
}

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

	jndex = 0;
	curr = g_env;
	while (curr)
	{
		index = 0;
		while (cmd->argv[++index])
			if (!ft_strcmp(cmd->argv[index], curr->key))
			{
				ft_lstdel_index((t_list**)&g_env,
				(void (*)(t_list *))del_env, jndex);
				return (TRUE);
			}
		jndex++;
		curr = curr->next;
	}
	return (TRUE);
}

static	t_bool	b_exit(t_command *cmd)
{
	long long		index;

	write(2, "exit\n", 5);
	cmd->argv[1] == NULL ? exit(0) : 1;
	index = (cmd->argv[1][0] == '-') || (cmd->argv[1][0] == '+') ? 1 : 0;
	if (ft_tablen(cmd->argv) > 2)
		return (error(E_ARGS, 1, cmd->cmd_name));
	while (cmd->argv[1] && cmd->argv[1][index])
		if (!ft_isdigit(cmd->argv[1][index++]))
			exit(error(E_EXIT_ARG, 255, cmd->argv[1]));
	index = ft_atol(cmd->argv[1]);
	if (cmd->argv[1] && ((index < 0 && cmd->argv[1][0] != '-')
	|| (index >= 0 && cmd->argv[1][0] == '-')))
		error(E_EXIT_ARG, 2, cmd->argv[1]);
	exit(index);
	return (TRUE);
}

t_bool			exec_builthin(t_command *cmd, int builthin)
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
	g_all->exit_status = check == TRUE ? 0 : g_all->exit_status;
	if (!cmd->simple)
		exit(g_all->exit_status);
	return (check);
}
