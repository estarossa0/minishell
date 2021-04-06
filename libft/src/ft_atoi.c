/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:30:44 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 18:55:36 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	is_digit(char char_digit)
{
	int	int_digit;

	int_digit = char_digit - '0';
	if (int_digit >= 0 && int_digit <= 9)
	{
		return (1);
	}
	return (0);
}

static	int	is_blank(char c, int sign)
{
	if (c == -1)
	{
		if (sign == 1)
			return (1);
		return (-1);
	}
	if (c == ' ' || c == '\n' || c == '\r' || c == '\f' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

static	int	get_sign(const char *str)
{
	int	sign;

	sign = -2;
	if (*str == '-')
		sign = 1;
	else if (*str == '+')
		sign = 0;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			result;
	int			digit;
	long int	lon;

	result = 0;
	lon = 0;
	sign = -2;
	while (is_blank(*str, 0))
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
			return (is_blank(-1, sign));
		str++;
	}
	if (sign)
		return (-result);
	return (result);
}

long long	ft_atol(const char *str)
{
	int			sign;
	int			digit;
	long long	lon;

	lon = 0;
	sign = -2;
	while (is_blank(*str, 0))
		str++;
	sign = get_sign(str);
	if (sign == 0 || sign == 1)
		str++;
	while (is_digit(*str))
	{
		digit = *str - '0';
		lon *= 10;
		if (sign == 1)
			lon = lon - digit;
		else
			lon = lon + digit;
		if ((sign == 1 && lon > 0) || (sign != 1 && lon < 0))
			return (is_blank(-1, sign));
		str++;
	}
	return (lon);
}
