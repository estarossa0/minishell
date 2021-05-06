/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:52 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 16:22:06 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	freak_out(int bits, char *line, int index)
{
	if (and_op(bits, BPIPE))
		return (error(E_SYNTAX, 1, &line[index]));
	else if (and_op(bits, BD_Q))
		return (error(E_SYNTAX, 1, &line[index]));
	else if (and_op(bits, BS_Q))
		return (error(E_SYNTAX, 1, &line[index]));
	else if (and_op(bits, BRED_TO) || and_op(bits, BRED_TO_APP)
		|| and_op(bits, BRED_FROM))
		return (error(E_SYNTAX, 1, &line[index]));
	return (TRUE);
}

void	chill(int *bits)
{
	bit_off(bits, BPIPE);
	bit_off(bits, BSEMIC);
	bit_off(bits, BCHECK);
	bit_off(bits, BRED_FROM);
	bit_off(bits, BRED_TO);
	bit_off(bits, BRED_TO_APP);
}

static	void	print_error(int err, char *need)
{
	if (err == E_SYNTAX)
		ft_fprintf(2, "parse error near `%s'\n", need);
	if (err == E_STANDARD)
		ft_fprintf(2, "%s.\n", strerror(errno));
	if (err == E_FILE)
		ft_fprintf(2, "`%s` %s\n", need, strerror(errno));
	if (err == E_NOCMD)
		ft_fprintf(2, "command not found: <%s>\n", need);
	if (err == E_WPATH)
		ft_fprintf(2, "no such file or directory: %s\n", need);
	if (err == E_ISDIR)
		ft_fprintf(2, "%s: Is a directory\n", need);
	if (err == E_ARGS)
		ft_fprintf(2, "%s: too many arguments\n", need);
	if (err == E_CD)
		ft_fprintf(2, "cd: %s: no such file or directory\n", need);
	if (err == E_NOT_VAL)
		ft_fprintf(2, "export: `%s\': not a valid identifier\n", need);
	if (err == E_EXIT_ARG)
		ft_fprintf(2, "exit: `%s\' is notnumeric argument\n", need);
	if (err == E_CD_HOME)
		ft_fprintf(2, "cd: HOME not set\n");
	if (err == E_NOTERM)
		ft_fprintf(2, "term not set\n", NULL);
}

int	error(int err, int exit_value, char *need)
{
	if (need && need[0] == '\0' && err == E_SYNTAX)
		need = "newline";
	else if (err == E_SYNTAX && need)
	{
		need[0] = *need;
		need[1] = '\0';
	}
	ft_fprintf(2, "minishell %d: ", err);
	print_error(err, need);
	g_all->exit_status = exit_value;
	return (exit_value);
}
