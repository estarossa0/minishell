/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:01:42 by arraji            #+#    #+#             */
/*   Updated: 2019/10/22 05:13:05 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	int		size;
	char	*tab;

	if (!s)
		return (NULL);
	index = 0;
	size = 0;
	while (s[size])
		size++;
	tab = (char *)malloc(size + 1);
	if (!tab)
		return (NULL);
	while (s[index])
	{
		tab[index] = (*f)(index, s[index]);
		index++;
	}
	tab[index] = 0;
	return (tab);
}
