/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shit_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:48:13 by arraji            #+#    #+#             */
/*   Updated: 2021/04/07 13:43:24 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	print_char(va_list ar, t_data *data)
{
	char	c;

	c = (char)va_arg(ar, int);
	data->printed_c = c;
	(data->index)++;
	ft_putchar_fd(data->printed_c, data->fd);
}

int	print_string(va_list ar, t_data *data)
{
	char	*str;

	str = (char *)va_arg(ar, char *);
	if (str)
		data->printed = ft_strdup(str);
	else
		data->printed = ft_strdup("(null)");
	(data->index)++;
	ft_putstr_fd(data->printed, data->fd);
	return (ft_end((void **)&(data->printed), NULL, 1));
}

int	print_decimal(va_list ar, t_data *data)
{
	long	rt;

	rt = va_arg(ar, int);
	data->printed = ft_ltoa(rt);
	ft_putstr_fd(data->printed, data->fd);
	(data->index)++;
	return (ft_end((void **)&(data->printed), NULL, 1));
}
