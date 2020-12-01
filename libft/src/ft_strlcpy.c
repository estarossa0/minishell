/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:14:50 by arraji            #+#    #+#             */
/*   Updated: 2019/11/05 21:17:37 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (!dest)
		return (src_len);
	while (src[i] != '\0' && i < (size - 1) && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i] != '\0' && size != 0)
	{
		dest[i] = '\0';
	}
	return (src_len);
}
