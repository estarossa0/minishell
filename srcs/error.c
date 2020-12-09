/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b-pearl <b-pearl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:52 by arraji            #+#    #+#             */
/*   Updated: 2020/12/07 17:47:02 by b-pearl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		freak_out(int bits, char *line, int index)
{
	if (AND(bits, BPIPE))
		return (error(E_SYNTAX, 1, &line[index]));
	else if (AND(bits, BD_Q))
		return (error(E_SYNTAX, 1, &line[index]));
	else if (AND(bits, BS_Q))
		return (error(E_SYNTAX, 1, &line[index]));
	else if (AND(bits, BRED_TO) || AND(bits, BRED_TO_APP)
	|| AND(bits, BRED_FROM))
		return (error(E_SYNTAX, 1, &line[index]));
	return (true);
}

void	chill(int *bits)
{
	BIT_OFF(*bits, BPIPE);
	BIT_OFF(*bits, BSEMIC);
	BIT_OFF(*bits, BCHECK);
	BIT_OFF(*bits, BRED_FROM);
	BIT_OFF(*bits, BRED_TO);
	BIT_OFF(*bits, BRED_TO_APP);
}

int		error(int err, int exit_value, char *need)
{
	if (need && need[0] == '\0')
		need = "newline";
	else if (err == E_SYNTAX && need)
	{
		need[0] = *need;
		need[1] = '\0';
	}
	ft_fprintf(2, "dumbshell %d: ", err);
	err == E_SYNTAX ? ft_fprintf(2, "parse error near `%s'\n", need) : 1;
	err == E_STANDARD ? ft_fprintf(2, "%s.\n", strerror(errno)) : 1;
	err == E_FILE ? ft_fprintf(2, "`%s` %s\n", need, strerror(errno)) : 1;
	err == E_NOCMD ? ft_fprintf(2, "command not found: %s\n", need) : 1;
	err == E_WPATH ? ft_fprintf(2, "no such file or directory: %s\n", need) : 1;
	err == E_ISDIR ? ft_fprintf(2, "%s: Is a directory\n", need) : 1;
	err == E_ARGS ? ft_fprintf(1, "%s: too many arguments\n", need) : 1;
	err == E_CD ? ft_fprintf(1, "cd: %s: no such file or directory\n", need) : 1;
	err == E_NOT_VAL ? ft_fprintf(2, "export: `%s\': not a valid identifier\n", need) : 1;
	err == E_EXIT_ARG ? ft_fprintf(2, "exit: `%s\' is notnumeric argument\n", need) : 1;
	err == E_CD_HOME ? ft_fprintf(2, "cd: HOME not set\n") : 1;
	g_all->exit_status = exit_value;
	return(1);
}

void	checker(char *line)
{
	int index = -1;

	write(1 , "check : ", 9);
	while (line[++index])
	{
		if (line[index] > 0)
		{
			ft_putchar_fd(line[index], 1);
			continue;
		}
		if (line[index] == WORD_SEP)
			ft_fprintf(1, "%s<word sep>%s", PRINT_RED, RESET);
		else if (line[index] == REMOVED)
			ft_fprintf(1, "%s<removed>%s", PRINT_RED, RESET);
		else if (line[index] == PIPELINE_SEP)
			ft_fprintf(1, "%s<pipeline sep>%s", PRINT_RED, RESET);
		else if (line[index] == CMD_SEP)
			ft_fprintf(1, "%s<cmd sep>%s", PRINT_RED, RESET);
		else if (line[index] == VAR)
			ft_fprintf(1, "%s<var>%s", PRINT_RED, RESET);
		else if (line[index] == RED_TO)
			ft_fprintf(1, "%s<red to>%s", PRINT_RED, RESET);
		else if (line[index] == RED_FROM)
			ft_fprintf(1, "%s<red from>%s", PRINT_RED, RESET);
		else if (line[index] == RED_TO_APP)
		{
			ft_fprintf(1, "%s<red to app>%s", PRINT_RED, RESET);
			// index++;
		}
	}
	write(1, "\n", 1);
}

void	list_checker2(t_all *all)
{
int		pipe_number;
	int		command_number;
	t_command	*cmd;
	t_pipeline	*pipe;
	t_args		*args;

	pipe_number = 1;
	pipe = all->pipe;
	while (pipe)
	{
		cmd = pipe->cmd_head;
		command_number = 1;
		ft_fprintf(1, "pipe %d:\n", pipe_number);
		while (cmd)
		{
			ft_fprintf(1, "cmd %d: ", command_number);
			int index = 0;
			while (cmd->argv[index])
			{
				ft_fprintf(1, "%s ", cmd->argv[index++]);
			}
			command_number++;
			write(1, "\n", 1);
			cmd = cmd->next;
		}
		pipe_number++;
		pipe = pipe->next;
	}
}

void	list_checker(t_all *all)
{
	int		pipe_number;
	int		command_number;
	t_command	*cmd;
	t_pipeline	*pipe;
	t_args		*args;

	pipe_number = 1;
	pipe = all->pipe;
	while (pipe)
	{
		cmd = pipe->cmd_head;
		command_number = 1;
		ft_fprintf(1, "pipe %d:\n", pipe_number);
		while (cmd)
		{
			args = cmd->list_args;
			ft_fprintf(1, "cmd %d: ", command_number);
			while (args)
			{
				if (args->type == 0)
				{
					if (args->c == WORD_SEP)
						ft_fprintf(1, "%s<WORD SEP>%s", PRINT_RED, RESET);
					else
						ft_fprintf(1, "%c", args->c);
				}
				else
				{
					ft_fprintf(1, "%s", args->str);
				}
				args = args->next;
			}
			command_number++;
			write(1, "\n", 1);
			cmd = cmd->next;
		}
		pipe_number++;
		pipe = pipe->next;
	}
}
