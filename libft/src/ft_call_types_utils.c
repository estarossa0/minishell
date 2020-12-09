/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_types_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 04:41:32 by arraji            #+#    #+#             */
/*   Updated: 2020/03/04 22:30:24 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	x_type(va_list ar, t_data *data)
{
	unsigned int	hexa;
	int				len;

	hexa = va_arg(ar, unsigned int);
	if (data->type == 6)
		data->printed = ft_to_hex(hexa, 0);
	else
		data->printed = ft_to_hex(hexa, 1);
	if (!(data->printed))
		return (-1);
	if (hexa == 0 && data->precision == 0 && (data->flag & PRE) == PRE)
		data->flag |= CRI;
	len = ft_strlen(data->printed);
	while (len < data->precision)
	{
		if (ft_stradd(&(data->printed), "0", -1) == -1)
			return (-1);
		len++;
	}
	data->pr_size = ft_strlen(data->printed);
	if (x_type_utils(data, len) == -1)
		return (-1);
	return (1);
}

int	x_type_utils(t_data *data, int len)
{
	while ((len++ < (data->width - 1)) && ((data->flag & PRE) == 0) &&
	((data->flag & ZE_FL) == ZE_FL))
		if (ft_stradd(&(data->printed), "0", -1) == -1)
			return (-1);
	data->pr_size = ft_strlen(data->printed);
	if ((data->flag & PRE) == PRE)
		data->fill_char = ' ';
	(data->index)++;
	return (1);
}

int	d_type_utils(t_data *data, int neg)
{
	if (neg)
		if (ft_stradd(&(data->printed), "-", -1) == -1)
			return (-1);
	data->pr_size = ft_strlen(data->printed);
	if ((data->flag & PRE) == PRE)
		data->fill_char = ' ';
	(data->index)++;
	return (1);
}

int	u_type_utils(t_data *data, int len)
{
	while ((len++ < (data->width - 1)) && ((data->flag & PRE) == 0) &&
	((data->flag & ZE_FL) == ZE_FL))
		if (ft_stradd(&(data->printed), "0", -1) == -1)
			return (-1);
	data->pr_size = ft_strlen(data->printed);
	if ((data->flag & PRE) == PRE)
		data->fill_char = ' ';
	(data->index)++;
	return (1);
}
