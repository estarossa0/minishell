/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:59:41 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:58:53 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

static	void	set_return(int data)
{
	if (WIFEXITED(data))
		g_all->exit_status = WEXITSTATUS(data);
	else if (WIFSIGNALED(data))
		g_all->exit_status = 128 + WTERMSIG(data);
	g_all->exit_status == 128 + SIGQUIT ? write(1, "Quit\n", 5) : 1;
}

bool			here_we_go(t_all *all)
{
	t_pipeline	*pipe;
	t_command	*cmd;
	int			pipefd[2];
	int			savefd[2];
	int			exit_data;

	pipe = all->pipe;
	fd_saving(savefd);
	while (pipe)
	{
		cmd = pipe->cmd_head;
		while(cmd)
		{
			cmd->simple = pipe->simple;
			cmd->cmd_name ? executing(cmd, pipefd, savefd) : 1;
			cmd = cmd->next;
		}
		while (g_pid != 0 && wait(&exit_data) != g_pid);
		set_return(exit_data);
		pipe = pipe->next;
	}
	fd_saving(savefd);
	return(true);
}

bool			get_data(t_all *all)
{
	all->exit_status == 0 ? ft_fprintf(1, BOLD PRINT_GR PS RESET) :
	ft_fprintf(1, BOLD PRINT_RED PS RESET);
	if ((all->parser.rt = get_next_line(1, &all->parser.line)) == -1)
		return (error(E_STANDARD, 1, NULL));
	if (all->parser.rt == 0)
	{
		write(1, "\n", 1);
		exit(0);
	}
	if (lexer(all->parser.line, &all->parser) == false ||
	parser(all->parser.line, all) == false)
			return (false);
	return (true);
}
