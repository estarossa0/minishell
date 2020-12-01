/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_handl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:12:35 by arraji            #+#    #+#             */
/*   Updated: 2020/03/05 09:32:06 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/*
**	0		precision		width		-			0	*	.	NONE
**	128			64			32			16			8	4	2	0
*/

static	int		is_flag(char c)
{
	if (c == '-' || c == '0' || c == '*' || c == '.' || ft_isdigit(c) == 1)
	{
		return (1);
	}
	return (0);
}

static	void	precision_set(const char *arg1, va_list ar, t_data *data)
{
	int precision;

	data->flag |= 2;
	(data->index)++;
	if (arg1[(data->index)] == '*')
	{
		precision = (int)va_arg(ar, int);
		data->precision = precision;
		if (precision >= 0)
			data->flag |= PRE;
		(data->index)++;
	}
	else if (ft_isdigit(arg1[data->index]))
	{
		precision = ft_atoi(&arg1[data->index]);
		data->precision = precision;
		while (ft_isdigit(arg1[data->index]))
			(data->index)++;
		data->flag |= PRE;
	}
	else
	{
		data->precision = 0;
		data->flag |= PRE;
	}
}

static	void	asterisk_set(va_list ar, t_data *data)
{
	int width;

	data->flag |= AST;
	(data->index)++;
	data->flag |= WIDTH;
	width = va_arg(ar, int);
	data->width = width;
	if (data->width < 0)
	{
		data->width *= -1;
		data->flag |= LE_ALI;
		data->fill_char = ' ';
	}
}

static	void	set_width(const char *arg1, t_data *data)
{
	data->width = ft_atoi(&arg1[(data->index)]);
	while (ft_isdigit(arg1[data->index]))
		(data->index)++;
	data->flag |= WIDTH;
}

void			check_flag(const char *arg1, va_list ar, t_data *data)
{
	while (is_flag(arg1[data->index]))
	{
		if (arg1[data->index] == '-')
		{
			data->flag |= LE_ALI;
			data->fill_char = ' ';
			(data->index)++;
		}
		else if (arg1[data->index] == '0' && (data->flag & WIDTH) == 0)
		{
			data->flag |= ZE_FL;
			if ((data->flag & LE_ALI) == 0)
				data->fill_char = '0';
			(data->index)++;
		}
		else if (ft_isdigit(arg1[(data->index)]))
			set_width(arg1, data);
		else if (arg1[data->index] == '*')
			asterisk_set(ar, data);
		else if (arg1[data->index] == '.')
			precision_set(arg1, ar, data);
	}
}
