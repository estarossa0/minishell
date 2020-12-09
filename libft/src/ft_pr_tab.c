/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 02:39:56 by arraji            #+#    #+#             */
/*   Updated: 2019/12/31 02:47:19 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pr_tap(char **tab, char *sep)
{
	size_t	index;

	index = 0;
	while (tab[index])
	{
		ft_fprintf(1, "%s", tab[index]);
		index++;
		if (tab[index])
			ft_fprintf(1, "%s", sep);
	}
	ft_fprintf(1, "\n");
}
