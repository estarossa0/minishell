/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:34:22 by arraji            #+#    #+#             */
/*   Updated: 2020/03/04 22:28:15 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_stradd(char **s1, char *s2, int type)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*copy;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (!(copy = ft_strdup(*s1)))
		return (-1);
	s1_len = ft_strlen(copy);
	s2_len = ft_strlen(s2);
	free(*s1);
	if (!(*s1 = (char *)malloc(s1_len + s2_len + 1)))
		return (ft_end((void **)&copy, NULL, -1));
	if (type > 0)
	{
		ft_strcpy(*s1, copy);
		ft_strcpy(&((*s1)[s1_len]), s2);
	}
	else
	{
		ft_strcpy(*s1, s2);
		ft_strcpy(&((*s1)[s2_len]), copy);
	}
	return (ft_end((void **)&copy, NULL, 1));
}
