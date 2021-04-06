/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:44:36 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 19:05:23 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	size(int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char				*result;
	unsigned int		n_tmp;
	int					index;

	if (n == 0)
	{
		result = (char *)malloc(sizeof(*result) + 1);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	index = 0;
	result = (char *)ft_calloc(size(n) + (n < 0) + 1, sizeof(*result));
	n_tmp = (n * n) / n;
	while (n_tmp > 0)
	{
		result[index++] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	if (n < 0)
		result[index] = '-';
	else
		result[index] = '\0';
	return (ft_revstr(result));
}
