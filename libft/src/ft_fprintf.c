/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 07:38:46 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 19:42:44 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static	t_data	*declare(int fd)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	new->type = 0;
	new->printed = NULL;
	new->printed_c = 0;
	new->index = 0;
	new->fd = fd;
	return (new);
}

static	int	strc_end(t_data **ptr, int rt)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (rt);
}

/*
**	X x u i		d p s c
**	0 0 0 0		0 0 0 0
*/

static	int	shit_printing(const char *arg1, va_list ar, t_data *data)
{
	int	ret;

	ret = 1;
	(data->index)++;
	data->type = check_type(arg1[(data->index)]);
	if (!(data->type))
		ft_putchar_fd(arg1[(data->index)++], data->fd);
	else if (data->type == C_T)
		print_char(ar, data);
	else if (data->type == S_T)
		ret = print_string(ar, data);
	else if (data->type == D_T)
		ret = print_decimal(ar, data);
	ft_reset(data);
	return (ret);
}

int	ft_fprintf(int fd, const char *arg1, ...)
{
	t_data				*data;
	va_list				ar;
	int					ret;

	ret = 0;
	data = declare(fd);
	va_start(ar, arg1);
	while (arg1[data->index])
	{
		if (arg1[data->index] == '%')
			ret = shit_printing(arg1, ar, data);
		else
			ft_putchar_fd(arg1[(data->index)++], data->fd);
	}
	va_end(ar);
	return (strc_end(&data, ret));
}
