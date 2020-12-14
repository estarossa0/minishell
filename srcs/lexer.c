/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:46:55 by arraji            #+#    #+#             */
/*   Updated: 2020/12/14 22:22:09 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
