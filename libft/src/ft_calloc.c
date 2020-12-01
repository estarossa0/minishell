/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 01:13:24 by arraji            #+#    #+#             */
/*   Updated: 2019/10/28 22:54:58 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_zero(void *tab, size_t num)
{
	char	*temp;

	temp = tab;
	while (num-- > 0)
	{
		*temp = 0;
		temp++;
	}
}

void			*ft_calloc(size_t num, size_t size)
{
	void *temp;

	temp = malloc(num * size);
	if (!temp)
		return (NULL);
	ft_zero(temp, (num * size));
	return (temp);
}
