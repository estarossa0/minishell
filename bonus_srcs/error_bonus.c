/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:34:08 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:36:48 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
	if (need && need[0] == '\0' && err == E_SYNTAX)
		need = "newline";
	else if (err == E_SYNTAX && need)
	{
		need[0] = *need;
		need[1] = '\0';
	}
	ft_fprintf(2, "minishell %d: ", err);
	err == E_SYNTAX ? ft_fprintf(2, "parse error near `%s'\n", need) : 1;
	err == E_STANDARD ? ft_fprintf(2, "%s.\n", strerror(errno)) : 1;
	err == E_FILE ? ft_fprintf(2, "`%s` %s\n", need, strerror(errno)) : 1;
	err == E_NOCMD ? ft_fprintf(2, "command not found: <%s>\n", need) : 1;
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
