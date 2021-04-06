/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 05:44:36 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 19:13:39 by arraji           ###   ########.fr       */
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

char	*ft_ltoa(unsigned long n)
{
	char				*result;
	unsigned long		n_tmp;
	unsigned long		index;

	if (n == 0)
	{
		result = (char *)malloc(sizeof(*result) + 1);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	index = 0;
	result = (char *)ft_calloc(size(n) + 1, sizeof(*result));
	n_tmp = n;
	while (n_tmp > 0)
	{
		result[index++] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	result[index] = '\0';
	return (ft_revstr(result));
}
