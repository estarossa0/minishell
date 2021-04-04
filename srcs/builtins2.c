/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:59:29 by arraji            #+#    #+#             */
/*   Updated: 2021/04/04 13:59:31 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_echo_print(char **str, int i, int newline)
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

t_bool		b_echo(t_command *cmd)
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

t_bool		b_cd(t_command *cmd)
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

t_bool		b_pwd(t_command *cmd)
{
	if (ft_tablen(cmd->argv) != 1)
		return (error(E_ARGS, 1, cmd->cmd_name));
	ft_fprintf(1, "%s\n", g_all->pwd);
	return (TRUE);
}

t_bool		b_export(t_command *cmd)
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
