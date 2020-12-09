/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shit_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:48:13 by arraji            #+#    #+#             */
/*   Updated: 2020/03/05 09:22:44 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	print_char(va_list ar, t_data *data)
{
	c_type(ar, data);
	if ((data->flag & LE_ALI) == LE_ALI)
		ft_putchar_fd(data->printed_c, data->fd);
	while ((data->width)-- > data->pr_size && (data->flag & WIDTH) == WIDTH)
	{
		ft_putchar_fd(data->fill_char, data->fd);
		(data->size_rt)++;
	}
	if ((data->flag & LE_ALI) == 0)
		ft_putchar_fd(data->printed_c, data->fd);
	(data->size_rt)++;
}

int		print_string(va_list ar, t_data *data)
{
	int max;

	if (s_type(ar, data) == -1)
		return (-1);
	max = (data->flag & PRE) == PRE ? 0 : data->pr_size;
	if (((data->flag & PRE) == PRE))
		while ((data->printed)[max] != '\0' && max < data->precision)
			max++;
	print_string_utils(data, 1);
	while ((data->width)-- > max && ((data->flag & WIDTH) == WIDTH))
	{
		ft_putchar_fd(data->fill_char, data->fd);
		(data->size_rt)++;
	}
	print_string_utils(data, -1);
	return (ft_end((void **)&(data->printed), NULL, 1));
}

int		print_corder(va_list ar, t_data *data)
{
	int max;
	int precision;

	if (p_type(ar, data) == -1)
		return (-1);
	precision = data->precision;
	while (precision-- > data->pr_size)
		ft_stradd(&(data->printed), "0", -1);
	max = (data->flag & PRE) == PRE ? 0 : data->pr_size + 2;
	if (((data->flag & PRE) == PRE))
	{
		while ((data->printed)[max] != '\0' && (data->flag & CRI) == 0)
			max++;
		max += 2;
	}
	print_corder_utils(data, 1);
	while ((data->width)-- > max && ((data->flag & WIDTH) == WIDTH))
	{
		ft_putchar_fd(' ', data->fd);
		(data->size_rt)++;
	}
	print_corder_utils(data, -1);
	return (ft_end((void **)&(data->printed), NULL, 1));
}

int		print_decimal(va_list ar, t_data *data)
{
	int max;

	if (d_type(ar, data) == -1)
		return (-1);
	max = (data->flag & PRE) == PRE ? 0 : data->pr_size;
	if (((data->flag & PRE) == PRE) && (data->flag & CRI) == 0)
		while ((data->printed)[max] != '\0')
			max++;
	if ((data->flag & LE_ALI) == LE_ALI && (data->flag & CRI) == 0)
	{
		ft_putstr_fd(data->printed, data->fd);
		data->size_rt += ft_strlen(data->printed);
	}
	while ((data->width)-- > max && (data->flag & WIDTH) == WIDTH)
	{
		ft_putchar_fd(data->fill_char, data->fd);
		(data->size_rt)++;
	}
	if ((data->flag & LE_ALI) == 0 && (data->flag & CRI) == 0)
	{
		ft_putstr_fd(data->printed, data->fd);
		data->size_rt += ft_strlen(data->printed);
	}
	return (ft_end((void **)&(data->printed), NULL, 1));
}

int		print_unsigned(va_list ar, t_data *data)
{
	int max;

	if (u_type(ar, data) == -1)
		return (-1);
	max = (data->flag & PRE) == PRE ? 0 : data->pr_size;
	if (((data->flag & PRE) == PRE) && (data->flag & CRI) == 0)
		while ((data->printed)[max] != '\0')
			max++;
	if ((data->flag & LE_ALI) == LE_ALI && (data->flag & CRI) == 0)
	{
		ft_putstr_fd(data->printed, data->fd);
		data->size_rt += ft_strlen(data->printed);
	}
	while ((data->width)-- > max && (data->flag & WIDTH) == WIDTH)
	{
		ft_putchar_fd(data->fill_char, data->fd);
		(data->size_rt)++;
	}
	if ((data->flag & LE_ALI) == 0 && (data->flag & CRI) == 0)
	{
		ft_putstr_fd(data->printed, data->fd);
		data->size_rt += ft_strlen(data->printed);
	}
	return (ft_end((void **)&(data->printed), NULL, 1));
}
