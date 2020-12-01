/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:34:44 by arraji            #+#    #+#             */
/*   Updated: 2020/02/06 01:47:01 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	double	get_int(char *str)
{
	int		index;
	double	result;

	result = 0;
	index = 0;
	if (str[index] == '-')
		index++;
	while (str[index] && ft_isalnum(str[index]))
		result = (result * 10) + (str[index++] - '0');
	return (result);
}

double			ft_atof(char *str)
{
	double	result;
	int		index;
	int		sing;
	double	mult;

	index = 0;
	mult = 0.1;
	if (str[index] == '-')
		index++;
	result = get_int(&str[index]);
	sing = (index == 1);
	while (ft_isalnum(str[index]))
		index++;
	if (str[index] == '.')
		index++;
	while (str[index] && ft_isalnum(str[index]))
	{
		result = result + (str[index++] - '0') * mult;
		mult *= 0.1;
	}
	if (sing)
		result *= -1;
	return (result);
}
