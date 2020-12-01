/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:57:16 by arraji            #+#    #+#             */
/*   Updated: 2020/03/05 09:30:31 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	c_type(va_list ar, t_data *data)
{
	char c;

	c = (char)va_arg(ar, int);
	data->printed_c = c;
	data->pr_size = 1;
	(data->index)++;
}

int		s_type(va_list ar, t_data *data)
{
	char *str;

	str = (char *)va_arg(ar, char *);
	data->printed = str != NULL ? ft_strdup(str) : NULL;
	if (data->printed == NULL)
	{
		if (!(data->printed = ft_strdup("(null)")))
			return (-1);
	}
	data->pr_size = ft_strlen(data->printed);
	(data->index)++;
	return (1);
}

int		p_type(va_list ar, t_data *data)
{
	unsigned	long	hexap;
	void				*p;

	p = va_arg(ar, void *);
	hexap = (unsigned long)p;
	if (p == NULL && data->precision == 0 && (data->flag & PRE) == PRE)
		data->flag |= CRI;
	if (!(data->printed = ft_to_hex(hexap, 0)))
		return (-1);
	data->pr_size = ft_strlen(data->printed);
	(data->index)++;
	return (1);
}

int		d_type(va_list ar, t_data *data)
{
	long	rt;
	int		len;
	int		neg;

	rt = va_arg(ar, int);
	neg = rt < 0;
	if (rt == 0 && data->precision == 0 && (data->flag & PRE) == PRE)
		data->flag |= CRI;
	rt *= (neg) ? -1 : 1;
	if (!(data->printed = ft_ltoa(rt)))
		return (-1);
	len = ft_strlen(data->printed);
	while (len < data->precision)
	{
		if (ft_stradd(&(data->printed), "0", -1) == -1)
			return (-1);
		len++;
	}
	while ((len++ < (data->width - 1)) && ((data->flag & PRE) == 0) &&
	((data->flag & ZE_FL) == ZE_FL && (data->flag & LE_ALI) == 0))
		if (ft_stradd(&(data->printed), "0", -1) == -1)
			return (-1);
	if (d_type_utils(data, neg) == -1)
		return (-1);
	return (1);
}

int		u_type(va_list ar, t_data *data)
{
	unsigned int	rt;
	int				len;

	rt = (unsigned int)va_arg(ar, unsigned int);
	if (!(data->printed = ft_ltoa(rt)))
		return (-1);
	if (rt == 0 && data->precision == 0 && (data->flag & PRE) == PRE)
		data->flag |= CRI;
	len = ft_strlen(data->printed);
	while (len < data->precision)
	{
		if (ft_stradd(&(data->printed), "0", -1) == -1)
			return (-1);
		len++;
	}
	if (u_type_utils(data, len) == -1)
		return (-1);
	data->pr_size = ft_strlen(data->printed);
	return (1);
}
