/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b-pearl <b-pearl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:46:55 by b-pearl           #+#    #+#             */
/*   Updated: 2020/12/01 22:55:57 by b-pearl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	bool	check_before(char current, int *data)
{
	if (current == '|')
	{
		if (AND(*data, BCHECK))
			return (error(E_SYNTAX, 1, &current));
		if (AND(*data, BPIPE))
			return (error(E_SYNTAX, 1, &current));
	}
	else if (current == ';')
	{
		if (AND(*data, BSEMIC))
			return (error(E_SYNTAX, 1, &current));
	}
	return (true);
}

bool	lexer(char *line, t_parser *parser)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (check_before(line[i], &parser->bits) == false ||
			sets(line, i, parser) == false)
			return (false);
	}
	if (freak_out(parser->bits, line, i) == false)
		return(false);
	chill(&parser->bits);
	return (true);
}
