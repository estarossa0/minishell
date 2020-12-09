/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:39 by arraji            #+#    #+#             */
/*   Updated: 2019/11/05 22:02:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	patch(const char *str, const char *to_find, size_t i)
{
	size_t j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (to_find[j] == str[i])
		{
			j++;
			i++;
			if (to_find[j] == '\0')
			{
				return (1);
			}
		}
		else
		{
			break ;
		}
	}
	return (0);
}

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		res;
	size_t	size;

	if (!str && !len)
		return (0);
	i = 0;
	size = 0;
	while (to_find[size])
		size++;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && size + i <= len)
	{
		if (str[i] == to_find[0])
		{
			res = patch(str, to_find, i);
			if (res == 1)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
