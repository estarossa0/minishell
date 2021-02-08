/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:34:19 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:36:45 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static	bool	peri_excuting(t_command *cmd, int builtin)
{
	if (!cmd->simple)
		if ((g_pid = fork()) == -1)
			return (error(E_STANDARD, 1, NULL));
	if (builtin >= 0 && g_pid == 0)
		return (exec_builthin(cmd, builtin));
	if (cmd->simple && (g_pid = fork()) == -1)
		return (error(E_STANDARD, 1, NULL));
	if (g_pid == 0)
	{
		if ((execve(cmd->full_path, cmd->argv, reverse_env())) == -1 )
			return (error(E_STANDARD, 1, NULL));
	}
	cmd->pid = g_pid;
	return (true);
}

void	post_executing(t_command *cmd, int pipefd[2], int savefd[2])
{
	if (cmd->next && cmd->next->type != SUB_OUT)
	{
		dup_close(pipefd[READ_END], STDIN_FILENO);
	}
	else
	{
		dup2(savefd[0], STDIN_FILENO) == -1 ? error(E_STANDARD, 1, NULL) : 1;
		dup2(savefd[1], STDOUT_FILENO) == -1 ? error(E_STANDARD, 1, NULL) : 1;
	}
}

void			executing(t_command *cmd, int pipefd[2], int savefd[2])
{
	int		builthin;

	builthin = is_builtin(cmd->cmd_name);
	if (pre_execute(cmd, pipefd, savefd, builthin) == true)
		peri_excuting(cmd, builthin);
	post_executing(cmd, pipefd, savefd);
}
