/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:19:29 by arraji            #+#    #+#             */
/*   Updated: 2019/10/22 22:03:14 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*point1;
	unsigned	char	*point2;

	point1 = (unsigned char *)s1;
	point2 = (unsigned char *)s2;
	while (n > 0 && ((unsigned char)*point1 == (unsigned char)*point2))
	{
		point1++;
		point2++;
		n--;
	}
	return (n == 0 ? 0 : (unsigned char)*point1 - (unsigned char)*point2);
}
