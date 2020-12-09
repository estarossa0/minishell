/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:18:27 by arraji            #+#    #+#             */
/*   Updated: 2020/03/05 09:34:15 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

char				*ft_to_hex(unsigned long hl, int type)
{
	char	*hex;
	int		index;

	index = 0;
	hex = (char*)malloc(11);
	if (hl == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	while (hl > 0)
	{
		if (type == 1)
			hex[index++] = hl % 16 > 9 ? hl % 16 + 55 : hl % 16 + 48;
		else
			hex[index++] = hl % 16 > 9 ? hl % 16 + 87 : hl % 16 + 48;
		hl = hl / 16;
	}
	hex[index] = '\0';
	return (ft_revstr(hex));
}

void				ft_reset(t_data *data)
{
	data->type = 0;
	data->flag = 0;
	data->printed = NULL;
	data->fill_char = ' ';
	data->printed_c = 0;
	data->precision = 0;
	data->width = 0;
	data->pr_size = 0;
}

unsigned	char	check_type(char c)
{
	unsigned char type;

	type = 0;
	if (c == 'c')
		type = C_T;
	else if (c == 's')
		type = S_T;
	else if (c == 'p')
		type = P_T;
	else if (c == 'd' || c == 'i')
		type = D_T;
	else if (c == 'u')
		type = U_T;
	else if (c == 'x')
		type = X_T;
	else if (c == 'X')
		type = XX_T;
	else if (c == '%')
		type = PERC;
	return (type);
}
