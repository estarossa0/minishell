/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:18:27 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 19:33:04 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_reset(t_data *data)
{
	data->type = 0;
	data->printed = NULL;
	data->printed_c = 0;
}

unsigned	char	check_type(char c)
{
	unsigned char	type;

	type = 0;
	if (c == 'c')
		type = C_T;
	else if (c == 's')
		type = S_T;
	else if (c == 'd' || c == 'i')
		type = D_T;
	return (type);
}
