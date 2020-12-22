#include "minishell_bonus.h"

void	skip_subshell(t_command **cmd, t_pipeline **pipe)
{
	int	depth;

	depth = 0;
	while (((*cmd)->type != SUB_OUT || depth != 0))
	{
		(*cmd)->type == SUB_IN ? depth++ : 1;
		(*cmd)->type == SUB_OUT ? depth-- : 1;
		(*cmd) = (*cmd)->next;
		if ((*cmd) == NULL)
		{
			(*pipe) = (*pipe)->next;
			(*cmd) = (*pipe)->cmd_head;
		}
	}
}

void	subshell_handle(t_command **cmd, t_pipeline **pipeline,
int pipefd[2], int savefd[2])
{
	t_command	*save;
	t_pipeline	*pipe_save;

	save = (*cmd)->next;
	pipe_save = *pipeline;
	skip_subshell(&save, &pipe_save);
	prepare_fd(save, pipefd, savefd);
	if ((g_pid = fork()) != -1 && g_pid == 0)
	{
		savefd[STDIN_FILENO] = dup(STDIN_FILENO);
		savefd[STDOUT_FILENO] = dup(STDOUT_FILENO);
		g_depth++;
		return ;
	}
	else
	{
		*pipeline = pipe_save;
		*cmd = save;
		post_executing(*cmd, pipefd, savefd);
	}
	(*cmd)->pid = g_pid;
}

void		subshell_parse(t_command **current, char *line, int index)
{
	t_command	*new;
	
	new = (t_command *)ft_lstadd_back((t_list **)current, malloc(sizeof(t_command)));
	*new = (t_command){0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
	if (line[index] == SUB_IN)
		(*current)->type = line[index];
	else
		new->type = line[index];
	*current = new;
}
