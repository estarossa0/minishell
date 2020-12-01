/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:19:35 by arraji            #+#    #+#             */
/*   Updated: 2020/06/02 21:24:14 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int	index;
	int	jndex;

	jndex = 0;
	index = 0;
	while (s1[index] || s2[jndex])
	{
		if (s1[index] != s2[jndex])
			return (s1[index] - s2[jndex]);
		index++;
		jndex++;
	}
	return (0);
}
