/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:34:34 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 23:06:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell_bonus.h"

void			finish_all(t_pipeline *pipe)
{
	t_command	*cmd;

	cmd = pipe->cmd_head;
	while (cmd)
	{
		if (cmd->pid > 0)
			kill(cmd->pid, SIGKILL);
		cmd = cmd->next;
	}
}

static	void	set_return(t_command *cmd, t_pipeline *pipe)
{
	int			ret;
	int			data;

	ret = 0;
	data = 0;
	while (ret != -1)
	{
		ret = wait(&data);
		if (ret == g_pid)
			finish_all(pipe);
		if (ret == g_pid && WIFEXITED(data))
			g_all->exit_status = WEXITSTATUS(data);
		else if (ret == g_pid && WIFSIGNALED(data))
		{
			g_all->exit_status = 128 + WTERMSIG(data);
			WTERMSIG(data) == SIGQUIT ? write(1, "Quit\n", 5) : 1;
		}
	}
	if (cmd && cmd->type == SUB_OUT)
		exit(g_all->exit_status);
	g_pid = 0;
}

void			apply_operation(t_pipeline **pipe, int fail)
{
	t_pipeline	*new;
	t_command	*cmd;
	int			next;

	new = (*pipe);
	fail = (fail != 0) ? 1 : 0;
	while (new && new->relation != PIPELINE_SEP)
	{
		if (new->relation == OP_OR)
			next = fail | 0;
		else
			next = !(fail ^ 0);
		if (next)
			break;
		new = new->next;
		cmd = new->cmd_head;
		while (cmd && cmd->type != SUB_OUT)
		{
			if (cmd->type != 0)
				skip_subshell(&cmd, &new);
			cmd = cmd->next;
		}
		if (cmd && cmd->type == SUB_OUT)
			exit(g_all->exit_status);
	}
	*pipe = new;
}

bool			here_we_go(t_all *all)
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
		while(cmd && cmd->type != SUB_OUT)
		{
			cmd->simple = pipe->simple;
			reverse_args(&(cmd->list_args));
			link_argv(cmd);
			if (cmd->type != 0)
				subshell_handle(&cmd, &pipe, pipefd, savefd);
			else
				cmd->cmd_name ? executing(cmd, pipefd, savefd): 1;
			cmd = cmd->next;
		}
		set_return(cmd, pipe);
		apply_operation(&pipe, all->exit_status);
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
