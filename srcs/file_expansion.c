/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:05:57 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 15:07:48 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_file(t_command *current, char *line, int *index)
{
	t_files	*new;

	new = (t_files *)malloc(sizeof(t_files));
	new->type = line[*index];
	new->file = get_next_word(line, index);
	ft_lstadd_back((t_list **)&(current->all_files), (t_list *)new);
}

static	void	overwrite_file(t_command *command)
{
	if (command->file)
	{
		free(command->file);
		close(command->fd);
	}
}

char	*get_next_word(char *line, int *index)
{
	int		save;
	char	*word;

	while (line[*index] < 0 && line[*index])
		(*index)++;
	save = *index;
	while (line[*index + 1] > 0 && line[*index + 1])
		(*index)++;
	word = ft_substr(line, save, (*index) - save + 1);
	return (word);
}

t_bool	parse_files(t_command *cmd)
{
	char	type;
	t_files	*iterator;

	iterator = cmd->all_files;
	while (iterator)
	{
		overwrite_file(cmd);
		type = iterator->type;
		cmd->file = iterator->file;
		if (type == RED_TO)
			cmd->fd = open(iterator->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (type == RED_FROM)
			cmd->fd = open(iterator->file, O_RDONLY);
		else if (type == RED_TO_APP)
			cmd->fd = open(iterator->file,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (cmd->fd < 0)
			return (error(E_FILE, 1, cmd->file));
		if (cmd->fd >= 0 && type == RED_FROM)
			dup_close(cmd->fd, STDIN_FILENO);
		if (cmd->fd >= 0 && ((type == RED_TO) || type == RED_TO_APP))
			dup_close(cmd->fd, STDOUT_FILENO);
		iterator = iterator->next;
	}
	return (TRUE);
}
