/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 23:01:39 by arraji            #+#    #+#             */
/*   Updated: 2021/02/08 08:14:35 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_index(t_list **list, void fun(t_list *) , int index)
{
	t_list	*save;
	t_list	*previous;

	previous = NULL;
	if (index == 0)
	{
		save = (*list);
		*list = (*list)->next;
		if (fun)
			fun(save);
		free(save);
	}
	else
	{
		save = *list;
		while (index--)
		{
			previous = save;
			save = save->next;
		}
		previous->next = save->next;
		if (fun)
			fun(save);
		free(save);
	}
	return (previous);
}
