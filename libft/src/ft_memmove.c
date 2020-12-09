/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:24:21 by arraji            #+#    #+#             */
/*   Updated: 2019/11/08 19:17:46 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	reverse(unsigned char *last_ori
, unsigned char *last_str, size_t len)
{
	while (len--)
	{
		*last_ori = *last_str;
		last_ori--;
		last_str--;
	}
}

void			*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned	char	*ori;
	unsigned	char	*str;
	unsigned	char	*last_ori;
	unsigned	char	*last_str;

	ori = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (src == dest)
		return (dest);
	if (dest == 0 && src == 0)
		return (0);
	if (ori < str)
		ft_memcpy(ori, str, len);
	else
	{
		last_ori = ori + (len - 1);
		last_str = str + (len - 1);
		reverse(last_ori, last_str, len);
	}
	return (dest);
}
