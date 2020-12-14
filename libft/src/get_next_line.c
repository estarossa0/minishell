/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:49:36 by arraji            #+#    #+#             */
/*   Updated: 2020/12/14 23:34:29 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		is_line(char *str, int rd)
{
	int index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		if (str[index++] == '\n')
			return (1);
	if (!rd && ft_strlen(str) == 0)
		return (1);
	return (0);
}

static	int		cutter(char **save, char **line)
{
	int		index;
	int		jndex;
	char	*copy;

	index = 0;
	jndex = 0;
	if (!(copy = ft_strdup(*save)))
		return (ft_end((void **)save, NULL, -1));
	free(*save);
	if (!(*line = (char *)malloc(ft_linelen(copy, 0) + 1)))
		return (ft_end((void **)&copy, NULL, -1));
	if (!(*save = malloc(ft_linelen(copy, 1) - ft_linelen(copy, 0) + 1)))
		return (ft_end((void **)&copy, (void **)line, -1));
	while (copy[index] != '\n' && copy[index] != '\0')
	{
		(*line)[index] = copy[index];
		index++;
	}
	(*line)[index] = '\0';
	if (copy[index] == '\n')
		index -= -1;
	while (copy[index] != '\0')
		(*save)[jndex++] = copy[index++];
	(*save)[jndex] = '\0';
	return (ft_end((void **)&copy, NULL, 1));
}

static	int		finish(char **line, char **save, char **buff)
{
	if (!(*line = ft_strdup("")))
		return (ft_end((void **)save, (void **)buff, -1));
	return (ft_end((void **)save, (void **)buff, 0));
}

static	int		fail(int fd, char **save)
{
	if (fd == -5)
	{
		ft_end((void**)save, NULL, -1);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	long	long		rd;
	static	char		*save = NULL;
	char				*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ft_end((void **)&save, NULL, -1));
	if (fail(fd, &save) == -1 || line == NULL || BUFFER_SIZE <= 0 || fd < 0)
		return (ft_end((void **)&buff, (void **)&save, -1));
	rd = 1;
	while (!is_line(save, rd))
	{
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
			return (ft_end((void **)&buff, (void **)&save, -1));
		buff[rd] = '\0';
		save = save == NULL ? (char *)malloc(rd + 1) : save;
		if (!save)
			return (ft_end((void **)&buff, NULL, -1));
		if (!rd && !ft_linelen(save, 1))
			return (finish(line, &save, &buff));
		if (ft_stradd(&save, buff, 1) == -1)
			return (ft_end((void **)&buff, (void **)&save, -1));
	}
	return (ft_end((void **)&buff, NULL, cutter(&save, line)));
}
