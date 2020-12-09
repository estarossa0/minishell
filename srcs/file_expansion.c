/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b-pearl <b-pearl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:05:57 by arraji            #+#    #+#             */
/*   Updated: 2020/12/07 17:52:38 by b-pearl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	overwrite_file(t_command *command)
{
	if (command->file)
	{
		free(command->file);
		close(command->fd);
	}
}

static	char	*get_next_word(char	*line, int *index)
{
	int		save;
	char	*word;
	while(line[*index] < 0 && line[*index])
		(*index)++;
	save = *index;
	while (line[*index + 1] > 0  && line[*index + 1])
		(*index)++;
	if (!(word = ft_substr(line, save, (*index) - save + 1)))
		error(E_STANDARD, 1, NULL);
	return (word);
}

bool		parse_file(t_command *current, char *line, int *index)
{
	char	type;

	type = line[*index];
	overwrite_file(current);
	if ((current->file = get_next_word(line, index)) == NULL)
		return (false);
	BIT_ON(current->read_type, -1 * type);
	if (type == RED_TO)
		current->fd = open(current->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == RED_FROM)
		current->fd = open(current->file, O_RDONLY);
	else if (type == RED_TO_APP)
		current->fd = open(current->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (current->fd < 0)
		return (error(E_FILE, 1, current->file));
	return (true);
}
