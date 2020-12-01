/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:36:37 by arraji            #+#    #+#             */
/*   Updated: 2019/10/22 08:43:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putcar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	long lnbr;

	lnbr = n;
	if (lnbr >= -2147483648 && lnbr <= 2147483648)
	{
		if (lnbr < 0)
		{
			lnbr = -lnbr;
			ft_putcar_fd('-', fd);
		}
		if (lnbr > 9)
		{
			ft_putnbr_fd(lnbr / 10, fd);
			ft_putcar_fd(lnbr % 10 + '0', fd);
		}
		else
		{
			ft_putcar_fd(lnbr + '0', fd);
		}
	}
}
