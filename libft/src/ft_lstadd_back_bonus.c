/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:37:37 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 18:31:27 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *save;

	if (!(*alst))
	{
		(*alst) = new;
		new->next = NULL;
	}
	else
	{
		save = *alst;
		while ((*alst)->next)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
		new->next = NULL;
		*alst = save;
	}
	return (new);
}
