/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:23:18 by arraji            #+#    #+#             */
/*   Updated: 2020/01/19 16:15:46 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_stlen(const char *str)
{
	size_t strlen;

	strlen = 0;
	if (str == NULL)
		return (0);
	while (str[strlen])
		strlen++;
	return (strlen);
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			s1_len;
	size_t			s2_len;
	size_t			index;
	int				res;

	if (n == 0)
		return (0);
	s1_len = (ft_stlen(s1));
	s2_len = (ft_stlen(s2));
	index = 0;
	res = 0;
	while (index <= s1_len && index <= s2_len && n > 0)
	{
		if (s1[index] != s2[index])
		{
			res = ((unsigned char)s1[index] - (unsigned char)s2[index]);
			return (res);
		}
		else
		{
			index++;
			n--;
		}
	}
	return (res);
}
