/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:59:53 by arraji            #+#    #+#             */
/*   Updated: 2019/10/22 11:40:38 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_set(char c, char const *sets)
{
	int index;

	index = 0;
	while (sets[index])
	{
		if (c == sets[index])
			return (1);
		index++;
	}
	return (0);
}

static	int	trim(char const *tab, char const *set, int index, int type)
{
	if (!type)
	{
		if (is_set(tab[index], set) && index > 0)
			return (trim(tab, set, index - 1, type));
		else
			return (index);
	}
	else
	{
		if (is_set(tab[index], set))
			return (trim(tab, set, index + 1, type));
		else
			return (index);
	}
	return (index);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int				index;
	unsigned	int	start;
	unsigned	int	last;
	char			*s2;

	index = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[index])
		index++;
	start = trim(s1, set, 0, 1);
	last = trim(s1, set, index - 1, 0);
	s2 = (char *)malloc(last - start + 2);
	if (!s2)
		return (NULL);
	index = 0;
	while (start < last + 1)
		s2[index++] = s1[start++];
	s2[index] = 0;
	return (s2);
}
