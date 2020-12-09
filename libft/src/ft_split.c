/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 04:22:53 by arraji            #+#    #+#             */
/*   Updated: 2019/11/06 01:00:12 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		word_count(char const *str, char c)
{
	int i;
	int word_number;

	i = 0;
	word_number = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == c || str[i] == '\0')
		{
			if (str[i - 1] != c)
				word_number++;
		}
	}
	return (word_number);
}

static	int		word_len(char const *str, char c, int *vars)
{
	int			word_l;

	word_l = 0;
	while (str[vars[2]] == c && str[vars[2]] != '\0')
		vars[2] += 1;
	while (str[vars[2]] != '\0')
	{
		if (str[vars[2]] != c && str[vars[2]] != '\0')
		{
			while (str[vars[2]] != c && str[vars[2]] != '\0')
			{
				vars[2] += 1;
				word_l++;
			}
			return (word_l);
		}
		else
		{
			vars[2] += 1;
		}
	}
	return (0);
}

static	void	assig(char **dest, char const *src, int *vars, char c)
{
	int			j;

	j = 0;
	while (src[vars[1]] == c && src[vars[1]] != '\0')
		vars[1] += 1;
	while (src[vars[1]] != '\0')
	{
		if (src[vars[1]] != c && src[vars[1]] != '\0')
		{
			while (src[vars[1]] != c && src[vars[1]] != '\0')
			{
				dest[vars[0]][j] = src[vars[1]];
				vars[1] += 1;
				j++;
			}
			dest[vars[0]][j] = '\0';
			return ;
		}
		else
		{
			vars[1] += 1;
		}
	}
}

/*
**vars[0] = i
**vars[1] = g_assi_car
**vars[2] = g_now_car
*/

static	char	**freeall(char **tab, int i)
{
	i--;
	while (i > 0)
		free(tab[i--]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		nb_w;
	int		ln_w;
	char	**tab;
	int		vars[3];

	vars[0] = 0;
	vars[1] = 0;
	vars[2] = 0;
	if (!s)
		return (NULL);
	nb_w = word_count(s, c);
	if (!(tab = (char **)malloc((nb_w + 1) * sizeof(char *))))
		return (NULL);
	while (vars[0] < nb_w)
	{
		ln_w = word_len(s, c, vars);
		if (!(tab[vars[0]] = (char *)malloc((ln_w + 1))))
			return (freeall(tab, vars[0]));
		assig(tab, s, vars, c);
		vars[0] += 1;
	}
	tab[vars[0]] = 0;
	return (tab);
}
