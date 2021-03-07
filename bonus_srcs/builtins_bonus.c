/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:33:17 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static	t_bool	b_echo(t_command *cmd)
{
	int		index;
	int		save;

	save = 0;
	index = 1;
	if (cmd->argv[1] && !ft_strcmp(cmd->argv[1], "-n") && index++)
		save = 1;
	while (cmd->argv[index])
	{
		ft_fprintf(1, "%s", cmd->argv[index++]);
		cmd->argv[index] != NULL ? ft_fprintf(1, " ") : 1;
	}
	save ? 1 : write(1, "\n", 1);
	g_all->exit_status = 0;
	return (TRUE);
}

static	t_bool	b_cd(t_command *cmd)
{
	int len;
	char	*home;
	t_bool	check;
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	len = ft_tablen(cmd->argv);
	check = TRUE;
	if (len > 2)
		check = error(E_ARGS, 1, cmd->cmd_name);
	if	(len == 1)
	{
		home = get_var_value("HOME");
		if (home)
			check = (chdir(home) == -1) ? error(E_CD, 1, home) : TRUE;
		else
			check = error(E_CD_HOME, 1, NULL);
	}
	else if (chdir(cmd->argv[1]) == -1)
		check = error(E_CD, 1, cmd->argv[1]);
	change_variables(old_pwd, check);
	return (check);
}

static	t_bool	b_pwd(t_command *cmd)
{
	char	*dir;

	if (ft_tablen(cmd->argv) != 1)
		return (error(E_ARGS, 1, cmd->cmd_name));
	dir = getcwd(NULL, 0);
	ft_fprintf(1, "%s\n", dir);
	free(dir);
	return (TRUE);
}


static	t_bool	b_export(t_command *cmd)
{
	int		index;
	t_env	*curr;

	index = 0;
	if (ft_tablen(cmd->argv) == 1)
		print_env();
	else
	{
		while (cmd->argv[++index])
		{
			curr = new_var(cmd->argv[index]);
			if (ft_strlen(curr->key) == 0)
				return (error(E_NOT_VAL, 1, curr->full_var));
			if (find_replace(curr))
				continue ;
			ft_lstadd_back((t_list **)&g_env, (void *)curr);
		}
	}
	return (TRUE);
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
				ft_lstdel_index((t_list**)&g_env, (void (*)(t_list *))del_env, jndex);
				return (TRUE);
			}
		jndex++;
		curr = curr->next;
	}
	return (TRUE);
}

static	t_bool	b_exit(t_command *cmd)
{
	int		index;

	index = 0;
	if (ft_tablen(cmd->argv) > 2)
		return (error(E_ARGS, 1, cmd->cmd_name));
	while (cmd->argv[1] && cmd->argv[1][index])
		if (!ft_isdigit(cmd->argv[1][index++]))
			return (error(E_EXIT_ARG, 2, cmd->argv[1]));
	cmd->argv[1] == NULL ? exit(0) : exit(ft_atoi(cmd->argv[1]));
	return (TRUE);
}

t_bool	exec_builthin(t_command *cmd, int builthin)
{
	t_bool	(*builthin_functions[7])(t_command *cmd) = {b_echo, b_cd, b_pwd, b_export, b_env, b_unset, b_exit};
	t_bool	check;

	check = builthin_functions[builthin](cmd);
	g_all->exit_status = check == TRUE ? 0 : g_all->exit_status;
	if (!cmd->simple)
		exit(g_all->exit_status);
	return (check);
}
