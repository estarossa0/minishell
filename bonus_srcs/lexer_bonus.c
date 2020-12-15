/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:34:40 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:36:38 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

bool	lexer(char *line, t_parser *parser)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (sets(line, i, parser) == false)
			return (false);
	}
	if (freak_out(parser->bits, line, i) == false)
		return(false);
	chill(&parser->bits);
	return (true);
}
