/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:36:39 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/28 11:35:36 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int		ft_putchar_fd(int fd, int c)
{
	int		res;

	res = write(fd, &c, 1);
	if (res < 0)
		return (FALSE);
	return (TRUE);
}

int		ft_putchar(int c)
{
	return (ft_putchar_fd(STDOUT_FILENO, c));
}
