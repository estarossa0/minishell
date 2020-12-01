/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpr_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:43:28 by arraji            #+#    #+#             */
/*   Updated: 2019/10/28 23:48:55 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpr_char(t_list *first)
{
	while (first)
	{
		ft_putstr_fd(first->content, 1);
		first = first->next;
	}
}
