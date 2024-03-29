/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:35:16 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:36:23 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

bool			check_token(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, SUBSHELL) && !(AND(parser->bits, TOKEN)))
	{
		if (!(AND(parser->bits, BRED_TO)) &&
		!(AND(parser->bits, BRED_TO_APP)) && !(AND(parser->bits, BRED_FROM)))
			return error(E_TOKEN, 2, &line[index]);
	}
	if (AND(parser->bits, SUBSHELL))
		BIT_ON(parser->bits, TOKEN);
	return true;
}

static	bool	set_pipe(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return (true);
	if (freak_out(parser->bits, line, index) == false)
		return (false);
	if (AND(parser->bits, BPIPE) || AND(parser->bits, BCHECK))
		return (error(E_SYNTAX, 1, &line[index]));
	BIT_OFF(parser->bits, OK_SOUT);
	BIT_OFF(parser->bits, SUBSHELL);
	BIT_ON(parser->bits, OK_SIN);
	line[index] = CMD_SEP;
	BIT_ON(parser->bits, BPIPE);
	return (true);
}

static	bool	set_s_quotes(char *line, int index, t_parser *parser)
{
	if (check_token(line, index, parser) == false)
		return false;
	if (AND(parser->bits, BD_Q))
		return true;
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BS_Q);
	return true;
}

static	bool	set_d_quotes(char *line, int index, t_parser *parser)
{
	if (check_token(line, index, parser) == false)
		return false;
	if (AND(parser->bits, BS_Q))
		return true;
	flip_bit(&parser->bits, BD_Q);
	chill(&parser->bits);
	line[index] = REMOVED;
	return true;
}

static	bool	set_semicolon(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return (true);
	if (freak_out(parser->bits, line, index) == false)
		return (false);
	if (AND(parser->bits, BSEMIC) || AND(parser->bits, BCHECK))
		return (error(E_SYNTAX, 1, &line[index]));
	BIT_ON(parser->bits, OK_SIN);
	BIT_OFF(parser->bits, SUBSHELL);
	line[index] = PIPELINE_SEP;
	BIT_ON(parser->bits, BSEMIC);
	return (true);
}

static	bool	set_dolar(char *line, int index, t_parser *parser)
{
	if (check_token(line, index, parser) == false)
		return false;
	if (AND(parser->bits, BS_Q))
		return true;
	chill(&parser->bits);
	if (line[index + 1] == ' ' || line[index + 1] == '|'|| line[index + 1] == ')' ||
	line[index + 1] == ';' || line[index + 1] == '$' || line[index + 1] == 0)
		return true;
	else if (line[index + 1 ] == '\'')
		line[index] = REMOVED;
	else if (line[index + 1] == '"')
		!(AND(parser->bits, BD_Q)) ? line[index] = REMOVED : 1;
	else
		line[index] = VAR;
	return true;
}

static	void	set_space(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BS_Q) || AND(parser->bits, BD_Q))
		return ;
	else
		line[index] = WORD_SEP;
	BIT_OFF(parser->bits, TOKEN);
}

static	bool	set_red_to(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return (true);
	if (AND(parser->bits, BRED_TO) || AND(parser->bits, BRED_TO_APP)
	|| AND(parser->bits, BRED_FROM))
		return (error(E_SYNTAX, 1, &line[index]));
	if (line[index + 1] == '>')
	{
		BIT_ON(parser->bits, BRED_TO_APP);
		line[index] = RED_TO_APP;
		line[index + 1] = RED_TO_APP;
	}
	else
	{
		BIT_ON(parser->bits, BRED_TO);
		line[index] = RED_TO;
	}
	BIT_OFF(parser->bits, OK_SOUT);
	return (true);
}

static	bool	set_red_from(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return (true);
	if (AND(parser->bits, BRED_TO) || AND(parser->bits, BRED_TO_APP)
	|| AND(parser->bits, BRED_FROM))
		return (error(E_SYNTAX, 1, &line[index]));
	BIT_OFF(parser->bits, OK_SOUT);
	line[index] = RED_FROM;
	BIT_ON(parser->bits, BRED_FROM);
	return (true);
}

static	bool	set_subshell_in(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return true;
	if (!(AND(parser->bits, OK_SIN)))
		return (error(E_SYNTAX, 1, &line[index]));
	g_depth++;
	BIT_OFF(parser->bits,OK_SOUT);
	line[index] = SUB_IN;
	return (true);
}

static	bool	set_subshell_out(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return true;
	if (!(AND(parser->bits, OK_SOUT)))
		return (error(E_SYNTAX, 1, &line[index]));
	g_depth--;
	BIT_OFF(parser->bits,OK_SIN);
	BIT_ON(parser->bits, SUBSHELL);
	line[index] = SUB_OUT;
	return (true);
}

static	bool	set_or(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return true;
	if (AND(parser->bits, BCHECK))
		return (error(E_OPERATOR, 1, &line[index]));
	if (freak_out(parser->bits, line, index) == false)
		return (false);
	BIT_ON(parser->bits, B_OR);
	BIT_OFF(parser->bits, SUBSHELL);
	BIT_OFF(parser->bits, OK_SOUT);
	BIT_ON(parser->bits, OK_SIN);
	line[index] = OP_OR;
	line[index + 1] = REMOVED;
	return true;
}

static	bool	set_and(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return true;
	if (AND(parser->bits, BCHECK))
		return (error(E_OPERATOR, 1, &line[index]));
	if (freak_out(parser->bits, line, index) == false)
		return (false);
	BIT_ON(parser->bits, B_AND);
	BIT_OFF(parser->bits, SUBSHELL);
	BIT_OFF(parser->bits, OK_SOUT);
	BIT_ON(parser->bits, OK_SIN);
	line[index] = OP_AND;
	line[index + 1] = REMOVED;
	return true;
}

bool			sets(char *line, int index, t_parser *parser)
{
	bool	check;

	check = true;
	if (line[index] < 0)
		return (true);
	else if (line[index] == '|' && line[index + 1] == line[index])
		check = set_or(line, index, parser);
	else if (line[index] == '&' && line[index + 1] == line[index])
		check = set_and(line, index, parser);
	else if (line[index] == '|')
		check = set_pipe(line, index, parser);
	else if (line[index] == '\'')
		check = set_s_quotes(line, index, parser);
	else if (line[index] == '"')
		check = set_d_quotes(line, index, parser);
	else if (line[index] == ';')
		check = set_semicolon(line, index, parser);
	else if (line[index] == '$')
		check = set_dolar(line, index, parser);
	else if (line[index] == ' ')
		set_space(line, index, parser);
	else if (line[index] == '>')
		check = set_red_to(line, index, parser);
	else if (line[index] == '<')
		check = set_red_from(line, index, parser);
	else if (line[index] == '(')
		check = set_subshell_in(line, index, parser);
	else if (line[index] == ')')
		check = set_subshell_out(line, index, parser);
	else
	{
		check = check_token(line, index, parser);
		chill(&parser->bits);
	}
	return (check);
}
