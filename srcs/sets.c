/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:34:12 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 16:16:16 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	set_dolar(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BS_Q))
		return ;
	chill(&parser->bits);
	if (line[index + 1] == ' ' || line[index + 1] == '|'
		|| line[index + 1] == '=' || line[index + 1] == ';'
		|| line[index + 1] == '$' || line[index + 1] == 0)
		return ;
	else if (line[index + 1] == '\'')
	{
		if ((and_op(parser->bits, BD_Q)))
			return ;
		line[index] = REMOVED;
	}
	else if (line[index + 1] == '"')
	{
		if (!(and_op(parser->bits, BD_Q)))
			line[index] = REMOVED;
	}
	else
		line[index] = VAR;
}

static	void	set_space(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BS_Q) || and_op(parser->bits, BD_Q))
		return ;
	else
		line[index] = WORD_SEP;
}

static	t_bool	set_red_to(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BD_Q) || and_op(parser->bits, BS_Q))
		return (TRUE);
	if (and_op(parser->bits, BRED_TO) || and_op(parser->bits, BRED_TO_APP)
		|| and_op(parser->bits, BRED_FROM))
		return (error(E_SYNTAX, 1, &line[index]));
	if (line[index + 1] == '>')
	{
		bit_on(&(parser->bits), BRED_TO_APP);
		line[index] = RED_TO_APP;
		line[index + 1] = RED_TO_APP;
	}
	else
	{
		bit_on(&(parser->bits), BRED_TO);
		line[index] = RED_TO;
	}
	return (TRUE);
}

static	t_bool	set_red_from(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BD_Q) || and_op(parser->bits, BS_Q))
		return (TRUE);
	if (and_op(parser->bits, BRED_TO) || and_op(parser->bits, BRED_TO_APP)
		|| and_op(parser->bits, BRED_FROM))
		return (error(E_SYNTAX, 1, &line[index]));
	line[index] = RED_FROM;
	bit_on(&(parser->bits), BRED_FROM);
	return (TRUE);
}

t_bool	sets(char *line, int index, t_parser *parser)
{
	t_bool	check;

	check = TRUE;
	if (line[index] < 0)
		return (TRUE);
	else if (line[index] == '|')
		check = set_pipe(line, index, parser);
	else if (line[index] == '\'')
		set_s_quotes(line, index, parser);
	else if (line[index] == '"')
		set_d_quotes(line, index, parser);
	else if (line[index] == ';')
		check = set_semicolon(line, index, parser);
	else if (line[index] == '$')
		set_dolar(line, index, parser);
	else if (line[index] == ' ')
		set_space(line, index, parser);
	else if (line[index] == '>')
		check = set_red_to(line, index, parser);
	else if (line[index] == '<')
		check = set_red_from(line, index, parser);
	else
		chill(&parser->bits);
	return (check);
}
