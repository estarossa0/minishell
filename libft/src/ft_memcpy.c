/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:16:18 by arraji            #+#    #+#             */
/*   Updated: 2019/11/05 21:07:15 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char	*ori;
	char	*str;

	ori = dest;
	str = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	while (num-- > 0)
	{
		*ori = *str;
		str++;
		ori++;
	}
	return (dest);
}
