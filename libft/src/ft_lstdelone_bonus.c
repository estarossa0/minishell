/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 04:37:40 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 16:14:15 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*save;

	if (!lst)
		return (NULL);
	save = lst->next;
	if (del)
		del(lst->content);
	free(lst);
	return (save);
}
