/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:02:21 by arraji            #+#    #+#             */
/*   Updated: 2020/12/14 14:01:12 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# ifndef PS
#  define PS "minishell$> "
# endif
# define PRINT_RED		"\033[1;31m"
# define PRINT_GR		"\033[1;32m"
# define BOLD			"\033[1;31m"
# define RESET			"\033[0m"
# define	BS_Q			1
# define	BD_Q			2
# define	BBACKSLASH		4
# define	BDOLAR			8
# define	BPIPE			16
# define	BSEMIC			32
# define	BCHECK			64
# define	BRED_TO			128
# define	BRED_TO_APP		256
# define	BRED_FROM		512
# define	WORD_SEP		-69
# define	REMOVED			-2
# define	PIPELINE_SEP	-3
# define	CMD_SEP			-4
# define	VAR				-5
# define	RED_TO			-8
# define	RED_FROM		-16
# define	RED_TO_APP		-32
# define	CNULL			-10
bool	get_data(t_all *);
bool	parser(char *line, t_all *all);
bool	lexer(char *, t_parser *parser);
bool	sets(char *line, int index, t_parser *parser);
void	add_word(t_args **list, char *word, int type);
bool	parse_file(t_command *current, char *line, int *index);
bool	reverse_parser(t_all *all);
#endif

