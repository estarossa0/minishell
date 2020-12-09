/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:14:04 by arraji            #+#    #+#             */
/*   Updated: 2019/11/08 21:17:03 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	len;

	n = 0;
	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (!dest && !size)
		return (len);
	while (dest[n] != '\0')
		n++;
	if (size <= n)
		return (len + size);
	else
		len += n;
	while (src[i] != '\0' && size > n + 1)
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (len);
}
