/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:46:55 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	lexer(char *line, t_parser *parser)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (sets(line, i, parser) == FALSE)
			return (FALSE);
	}
	if (freak_out(parser->bits, line, i) == FALSE)
		return (FALSE);
	chill(&parser->bits);
	return (TRUE);
}
