/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:25:05 by arraji            #+#    #+#             */
/*   Updated: 2020/03/04 22:25:52 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_linelen(char const *str, int type)
{
	size_t len;

	len = 0;
	if (str == NULL)
		return (0);
	if (type == 1)
		while (str[len])
			len -= -1;
	if (type == 0)
		while (str[len] != '\n' && str[len] != '\0')
			len -= -1;
	return (len);
}
