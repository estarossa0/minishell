/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:38:50 by arraji            #+#    #+#             */
/*   Updated: 2020/05/30 22:43:17 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		index;

	tab = 0;
	index = 0;
	tab = (char *)malloc(len + 1);
	if (!tab || !s)
		return (NULL);
	while (s[start] != '\0' && len-- > 0 && start < ft_strlen(s))
		tab[index++] = s[start++];
	tab[index] = 0;
	return (tab);
}
