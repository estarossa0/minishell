/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:20 by arraji            #+#    #+#             */
/*   Updated: 2021/04/07 13:48:02 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_hlist
{
	struct s_hlist	*next;
	struct s_hlist	*prev;
	char			*cmd;
	char			*updated;
	int				llen;
}				t_hlist;

typedef struct s_hist
{
	t_hlist		*list;
	t_hlist		*head;
	t_hlist		*end;
}				t_hist;

typedef struct s_files
{
	struct s_files	*next;
	char			*file;
	int				type;
}				t_files;

typedef struct s_parser
{
	int		bits;
	char	*line;
	int		rt;
}				t_parser;

typedef struct s_args
{
	struct s_args	*next;
	char			c;
	char			*str;
	int				type;
}				t_args;

typedef struct s_command
{
	struct s_command	*next;
	char				*cmd_name;
	char				**argv;
	struct s_args		*list_args;
	char				*full_path;
	int					fd;
	char				*file;
	t_files				*all_files;
	char				read_type;
	int					simple;
}				t_command;

typedef struct s_pipeline
{
	struct s_pipeline	*next;
	int					simple;
	struct s_command	*cmd_head;
}				t_pipeline;

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*value;
	char			*full_var;
	int				type;
	int				plus;
}				t_env;

typedef struct s_all
{
	unsigned char	exit_status;
	t_parser		parser;
	t_pipeline		*pipe;
	char			*pwd;
	t_hist			hist;
	char			**environ;
	t_env			*env;
	int				total_env;
	pid_t			pid;
}				t_all;
#endif
