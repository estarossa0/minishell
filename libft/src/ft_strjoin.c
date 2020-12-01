/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 02:21:51 by arraji            #+#    #+#             */
/*   Updated: 2019/10/22 08:44:17 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned	int	ft_stlen(char const *tab)
{
	unsigned	int len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

char					*ft_strjoin(char const *s1, char const *s2)
{
	unsigned	int	index;
	unsigned	int	jndex;
	unsigned	int s1_len;
	unsigned	int s2_len;
	char			*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	jndex = 0;
	s1_len = ft_stlen(s1);
	s2_len = ft_stlen(s2);
	s3 = (char *)malloc(s1_len + s2_len + 1);
	if (!s3)
		return (NULL);
	while (jndex < s1_len)
		s3[index++] = s1[jndex++];
	jndex = 0;
	while (jndex < s2_len)
		s3[index++] = s2[jndex++];
	s3[index] = 0;
	return (s3);
}
