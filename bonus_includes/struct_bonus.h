/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:20 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:38:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H
# ifndef D_ERROR
# error "include only minishell.h"
# endif
typedef	struct	s_parser
{
	int		bits;
	char	*line;
	int		rt;
}				t_parser;

typedef	struct	s_args
{
	struct	s_args	*next;
	char			c;
	char			*str;
	int				type;
}				t_args;

typedef	struct	s_command
{
	struct	s_command	*next;
	char				*cmd_name;
	char				**argv;
	struct	s_args		*list_args;
	char				*full_path;
	int					fd;
	char				*file;
	char				read_type;
	int					simple;
	int					relation;
	int					type;
	int					pid;
}				t_command;

typedef	struct s_pipeline
{
	struct	s_pipeline	*next;
	int					simple;
	struct	s_command	*cmd_head;
}				t_pipeline;

typedef	struct	s_all
{
	unsigned char	exit_status;
	t_parser		parser;
	t_pipeline		*pipe;
}				t_all;

typedef	struct	s_env
{
	struct	s_env	*next;
	char			*key;
	char			*value;
	char			*full_var;
}				t_env;
#endif
