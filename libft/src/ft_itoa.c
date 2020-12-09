/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:44:36 by arraji            #+#    #+#             */
/*   Updated: 2020/02/04 05:26:03 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size(int n)
{
	int size;

	size = 0;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char				*result;
	unsigned int		n_tmp;
	int					sign;
	int					index;

	if (n == 0)
	{
		if (!(result = (char *)malloc(sizeof(*result) + 1)))
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	sign = n < 0;
	index = 0;
	if (!(result = (char *)ft_calloc(size(n) + sign + 1, sizeof(*result))))
		return (NULL);
	n_tmp = sign ? (unsigned int)-n : (unsigned int)n;
	while (n_tmp > 0)
	{
		result[index++] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	result[index] = sign ? '-' : '\0';
	return (ft_revstr(result));
}
