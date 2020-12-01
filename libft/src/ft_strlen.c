/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:01:30 by arraji            #+#    #+#             */
/*   Updated: 2020/03/11 19:33:08 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(char const *str)
{
	size_t len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len -= -1;
	return (len);
}
