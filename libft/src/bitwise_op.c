/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:40:28 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 18:02:58 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		and_op(int x, int y)
{
	return (((x & y) == y));
}

int		nand_op(int x, int y)
{
	return (((x & y) == 0));
}

void	bit_on(int *x, int y)
{
	*x |= y;
}

void	bit_off(int *x, int y)
{
	*x &= ~y;
}
