/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpr_char_en.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:13:15 by arraji            #+#    #+#             */
/*   Updated: 2019/10/29 03:18:03 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpr_char_en(t_list *first)
{
	while (first)
	{
		ft_putstr_fd((char *)first->content, 1);
		ft_putchar_fd('\n', 1);
		first = first->next;
	}
}
