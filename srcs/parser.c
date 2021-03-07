/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:11 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	init_list(t_command **current, t_all *all)
{
	if (all->pipe == NULL)
	{
		ft_lstadd_back((t_list **)&(all->pipe), malloc(sizeof(t_pipeline)));
		all->pipe->cmd_head = NULL;
		all->pipe->simple = 1;
		*current = (t_command *)ft_lstadd_back((t_list **)&(all->pipe->cmd_head)
		, malloc(sizeof(t_command)));
		**current = (t_command){0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
	}
}

static	void	switch_current(t_command **current, char *line,
int index, t_all *all)
{
	t_pipeline	*pipe;

	if (line[index] == PIPELINE_SEP)
	{
		pipe = (t_pipeline*)ft_lstadd_back((t_list **)&(all->pipe),
		malloc(sizeof(t_pipeline)));
		pipe->cmd_head = NULL;
		pipe->simple = 1;
		*current = (t_command *)ft_lstadd_back((t_list **)&(pipe->cmd_head),
		malloc(sizeof(t_command)));
	}
	else
	{
		pipe = all->pipe;
		while (pipe->next)
			pipe = pipe->next;
		pipe->simple = 0;
		*current = (t_command *)ft_lstadd_back((t_list **)current,
		malloc(sizeof(t_command)));
	}
	**current = (t_command){0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
}

void			add_word(t_args **list, char *word, int type)
{
	t_args	*current;

	current = (t_args *)ft_lstadd_back((t_list **)list, malloc(sizeof(t_args)));
	current->type = type;
	if (type == 0)
		current->c = *word;
	else if (type == 1)
	{
		current->str = word;
		current->c = CNULL;
	}
}

void			hardcode_empty_arg(char *line, int index)
{
	if ((index == 0 || line[index - 1] == WORD_SEP) &&
	line[index + 1] == REMOVED
	&& (line[index + 2] == WORD_SEP || line[index + 2] == '\0'))
		line[index] = '\0';
}

t_bool			parser(char *line, t_all *all)
{
	int			index;
	t_command	*current;

	index = 0;
	while (line[index] && line[index] == WORD_SEP)
		index++;
	index--;
	while (line[++index])
	{
		if (line[index] == REMOVED)
			hardcode_empty_arg(line, index);
		if (line[index] == REMOVED)
			continue;
		init_list(&current, all);
		if (line[index] == RED_FROM || line[index] == RED_TO
		|| line[index] == RED_TO_APP)
			add_file(current, line, &index);
		else if (line[index] == VAR)
			variable_expansion(line, &index, current);
		else if (line[index] == CMD_SEP || line[index] == PIPELINE_SEP)
			switch_current(&current, line, index, all);
		else
			add_word(&current->list_args, &line[index], 0);
	}
	return (TRUE);
}
