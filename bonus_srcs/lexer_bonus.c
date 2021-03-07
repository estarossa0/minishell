/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:34:40 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
		return(FALSE);
	if (g_depth != 0)
		return (error(E_DEPTH, 1, NULL));
	chill(&parser->bits);
	return (TRUE);
}
