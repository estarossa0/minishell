/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:19:35 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 19:10:34 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
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
