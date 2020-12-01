/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:37:28 by arraji            #+#    #+#             */
/*   Updated: 2019/10/29 03:53:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t len)
{
	unsigned char *temp;

	temp = (unsigned char *)str;
	while (len--)
	{
		if (*temp == (unsigned char)value)
			return (temp);
		temp++;
	}
	return (0);
}
