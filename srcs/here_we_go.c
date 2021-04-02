/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:59:41 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 18:38:44 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		set_state(void)
{
	struct termios		term;

	if (tgetent(0, NULL) < 1)
		exit(error(E_NOTERM, 1, NULL));
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	return (1);
}

static	void	set_return(void)
{
	int			ret;
	int			data;

	ret = 0;
	data = 0;
	while (ret != -1)
	{
		ret = wait(&data);
		if (ret == g_pid && WIFEXITED(data))
			g_all->exit_status = WEXITSTATUS(data);
		else if (ret == g_pid && WIFSIGNALED(data))
		{
			g_all->exit_status = 128 + WTERMSIG(data);
			WTERMSIG(data) == SIGQUIT ? write(1, "Quit\n", 5) : 1;
		}
	}
	g_pid = 0;
}

t_bool			here_we_go(t_all *all)
{
	t_pipeline	*pipe;
	t_command	*cmd;
	int			pipefd[2];
	int			savefd[2];

	pipe = all->pipe;
	fd_saving(savefd);
	while (pipe)
	{
		cmd = pipe->cmd_head;
		while (cmd)
		{
			cmd->simple = pipe->simple;
			reverse_args(&(cmd->list_args));
			link_argv(cmd);
			executing(cmd, pipefd, savefd);
			cmd = cmd->next;
		}
		set_return();
		pipe = pipe->next;
	}
	fd_saving(savefd);
	return (TRUE);
}

t_bool			get_data(t_all *all)
{
	set_state();
	(all->exit_status == 0) ? ft_fprintf(1, "%s%s%s%s", BOLD, PRINT_GR, PS,
	RESET) : ft_fprintf(1, "%s%s%s%s", BOLD, PRINT_RED, PS, RESET);
	all->parser.rt = readline(&all->parser.line, &(all->hist));
	if (all->parser.rt == -1)
		return (error(E_STANDARD, 1, NULL));
	else if (all->parser.rt == 0)
	{
		write(1, "exit\n", 6);
		exit(0);
	}
	if (lexer(all->parser.line, &all->parser) == FALSE ||
	parser(all->parser.line, all) == FALSE)
		return (FALSE);
	return (TRUE);
}