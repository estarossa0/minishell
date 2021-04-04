/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:00:32 by arraji            #+#    #+#             */
/*   Updated: 2021/04/04 14:03:20 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	set_pipe(char *line, int index, t_parser *parser)
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

void	set_s_quotes(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BD_Q))
		return ;
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BS_Q);
}

void	set_d_quotes(char *line, int index, t_parser *parser)
{
	if (and_op(parser->bits, BS_Q))
		return ;
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BD_Q);
}

t_bool	set_semicolon(char *line, int index, t_parser *parser)
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
