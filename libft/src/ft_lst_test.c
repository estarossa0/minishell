/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:58:02 by arraji            #+#    #+#             */
/*   Updated: 2019/10/31 02:43:08 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_test(void)
{
	t_list	*first;
	t_list	*move;
	t_list	*save;
	int		index;

	move = (t_list *)malloc(sizeof(t_list));
	save = move;
	index = 4;
	while (index)
	{
		move->next = (t_list *)malloc(sizeof(t_list));
		move = move->next;
		index--;
	}
	move->next = NULL;
	move = save;
	move->content = ft_strdup("hello");
	move->next->content = ft_strdup("word");
	move->next->next->content = ft_strdup("how");
	move->next->next->next->content = ft_strdup("are");
	move->next->next->next->next->content = ft_strdup("you");
	first = save;
	return (first);
}
