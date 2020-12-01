/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:01:28 by arraji            #+#    #+#             */
/*   Updated: 2019/10/29 03:52:55 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int car, size_t num)
{
	unsigned	char	*ori;
	unsigned	char	*str;
	size_t				index;

	ori = (unsigned char *)dest;
	str = (unsigned char *)src;
	index = 0;
	while (index < num)
	{
		ori[index] = str[index];
		if (str[index] == (unsigned char)car)
		{
			return ((void *)&ori[index + 1]);
		}
		index++;
	}
	return (NULL);
}
