/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 07:13:05 by arraji            #+#    #+#             */
/*   Updated: 2019/10/30 23:56:38 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*add(void *data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = data;
	new->next = NULL;
	return (new);
}

static	void	clear(t_list *first, void (*del)(void *))
{
	t_list *nxt;

	nxt = NULL;
	while ((first))
	{
		nxt = (first)->next;
		(*del)((first->content));
		free((first));
		(first) = nxt;
	}
	first = NULL;
	free(nxt);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *first;
	t_list *save;

	if (!lst)
		return (NULL);
	first = add((*f)(lst->content));
	if (!first)
		return (NULL);
	save = first;
	lst = lst->next;
	while (lst)
	{
		first->next = add((*f)(lst->content));
		if (!first->next)
		{
			clear(save, del);
			return (NULL);
		}
		first = first->next;
		lst = lst->next;
	}
	return (save);
}
