/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:30:44 by arraji            #+#    #+#             */
/*   Updated: 2019/11/07 23:04:09 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	is_digit(char char_digit)
{
	int int_digit;

	int_digit = char_digit - '0';
	if (int_digit >= 0 && int_digit <= 9)
	{
		return (1);
	}
	return (0);
}

static	int	is_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\f' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

static	int	get_sign(const char *str)
{
	int sign;

	sign = -2;
	if (*str == '-')
		sign = 1;
	else if (*str == '+')
		sign = 0;
	return (sign);
}

int			ft_atoi(const char *str)
{
	int			sign;
	int			result;
	int			digit;
	long int	lon;

	result = 0;
	lon = 0;
	sign = -2;
	while (is_blank(*str))
		str++;
	sign = get_sign(str);
	if (sign == 0 || sign == 1)
		str++;
	while (is_digit(*str))
	{
		digit = *str - '0';
		lon = (10 * lon) + digit;
		result = (10 * result) + digit;
		if (lon < 0)
			return (sign) == 1 ? (0) : (-1);
		str++;
	}
	return (sign) == 1 ? (-result) : (result);
}
