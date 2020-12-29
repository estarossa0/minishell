/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:35:48 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/28 09:26:49 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int		ft_putstr_fd(int fd, char *str)
{
	while (*str)
	{
		if (!(ft_putchar_fd(fd, *str)))
			return (FALSE);
		str++;
	}
	return (TRUE);
}