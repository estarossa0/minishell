/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:28:01 by arraji            #+#    #+#             */
/*   Updated: 2019/10/29 04:05:56 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int value)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	while (index != -1)
	{
		if (str[index] == (unsigned char)value)
			return ((char*)&str[index]);
		index--;
	}
	return (NULL);
}
