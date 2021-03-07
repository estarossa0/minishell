/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:19:13 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_bool	built_handle(t_command *cmd, int builtin, int pipefd[2])
{
	if (!cmd->simple && (g_pid = fork()) == -1)
		return (error(E_STANDARD, 1, NULL));
	if (g_pid == 0)
		close(pipefd[READ_END]);
	else
		return (TRUE);
	return (exec_builthin(cmd, builtin));
}

static	t_bool	execve_handle(t_command *cmd, int pipefd[2])
{
	if ((g_pid = fork()) == -1)
		return (error(E_STANDARD, 1, NULL));
	if (g_pid == 0)
		close(pipefd[READ_END]);
	else
		return (TRUE);
	if (!cmd->cmd_name)
		exit(0);
	if ((execve(cmd->full_path, cmd->argv, reverse_env())) == -1)
		return (error(E_STANDARD, 1, NULL));
	return (TRUE);
}

static	t_bool	peri_excuting(t_command *cmd, int builtin, int pipefd[2])
{
	if (builtin >= 0 && cmd->cmd_name)
		return (built_handle(cmd, builtin, pipefd));
	else
		return (execve_handle(cmd, pipefd));
}

static	void	post_executing(t_command *cmd, int pipefd[2], int savefd[2])
{
	if (cmd->next)
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

	builthin = cmd->cmd_name ? is_builtin(cmd->cmd_name) : 0;
	if (pre_execute(cmd, pipefd, savefd, builthin) == TRUE)
		peri_excuting(cmd, builthin, pipefd);
	post_executing(cmd, pipefd, savefd);
}
