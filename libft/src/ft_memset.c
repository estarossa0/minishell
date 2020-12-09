/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:09:59 by arraji            #+#    #+#             */
/*   Updated: 2019/11/08 19:11:46 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *tab, int valeur, size_t lenght)
{
	size_t	index;
	char	*temp;

	index = 0;
	temp = tab;
	while (index++ < lenght)
	{
		*temp = (unsigned char)valeur;
		temp++;
	}
	return (tab);
}
