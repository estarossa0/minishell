/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:34:12 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 18:10:20 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_bool	set_pipe(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BD_Q) || and_op(parser->bits, BS_Q))
		return (TRUE);
	if (freak_out(parser->bits, line, index) == FALSE)
		return (FALSE);
	if (and_op(parser->bits, BPIPE) || and_op(parser->bits, BCHECK))
		return (error(E_SYNTAX, 1, &line[index]));
	line[index] = CMD_SEP;
	bit_on(&(parser->bits), BPIPE);
	return (TRUE);
}

static	void	set_s_quotes(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BD_Q))
		return ;
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BS_Q);
}

static	void	set_d_quotes(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BS_Q))
		return ;
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BD_Q);
}

static	t_bool	set_semicolon(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BD_Q) || and_op(parser->bits, BS_Q))
		return (TRUE);
	if (freak_out(parser->bits, line, index) == FALSE)
		return (FALSE);
	if (and_op(parser->bits, BSEMIC) || and_op(parser->bits, BCHECK))
		return (error(E_SYNTAX, 1, &line[index]));
	line[index] = PIPELINE_SEP;
	bit_on(&(parser->bits), BSEMIC);
	return (TRUE);
}

static	void	set_dolar(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BS_Q))
		return ;
	chill(&parser->bits);
	if (line[index + 1] == ' ' || line[index + 1] == '|' ||
	line[index + 1] == ';' || line[index + 1] == '$' || line[index + 1] == 0)
		return ;
	else if (line[index + 1] == '\'')
	{
		if ((and_op(parser->bits, BD_Q)))
			return ;
		line[index] = REMOVED;
	}
	else if (line[index + 1] == '"')
		!(and_op(parser->bits, BD_Q)) ? line[index] = REMOVED : 1;
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

t_bool			sets(char *line, int index, t_parser *parser)
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
