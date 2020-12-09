/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:13:09 by arraji            #+#    #+#             */
/*   Updated: 2020/02/02 18:16:25 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		valid_f(char *str)
{
	int		index;

	index = 0;
	if (str[index] == '-')
		index++;
	if (ft_isdigit(str[index]) == 0)
		return (0);
	while (str[index] != '.' && str[index] != '\0')
	{
		if (ft_isdigit(str[index]) == 0)
			return (0);
		index++;
	}
	if (str[index] == '.')
	{
		index++;
		if (ft_isdigit(str[index]) == 0)
			return (0);
	}
	while (str[index])
	{
		if (ft_isdigit(str[index++]) == 0)
			return (0);
	}
	return (1);
}

int		valid_d(char *str)
{
	int		index;

	index = 0;
	if (str[index] == '-')
		index++;
	while (str[index])
	{
		if (ft_isdigit(str[index++]) == 0)
			return (0);
	}
	return (1);
}

int		valid_num(char *str, int type)
{
	int rt;

	if (type == 1)
		rt = valid_d(str);
	else
		rt = valid_f(str);
	return (rt);
}
