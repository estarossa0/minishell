/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:27:29 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/29 08:14:13 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
** Gets the database for current terminal
*/

int			init_terminal(void)
{
	char	*term_type;
	int		success;

	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		ft_putstr_fd(2, "Specify a terminal type with `setenv \
							TERM <yourtype>'.\n");
		return (FALSE);
	}
	success = tgetent(NULL, term_type);
	if (success < 0)
	{
		ft_putstr_fd(2, "Could not access the termcap data base.\n");
		return (FALSE);
	}
	if (success == 0)
	{
		ft_putstr_fd(2, "Terminal type provided is not defined.\n");
		return (FALSE);
	}
	return (TRUE);
}


/*
** Configure termios flags
**		Disables Echo : no Character output
**		Disables Connonical Mode : Does Not Await On Carriage Return
**		(Min, Time) determine the circumstances in which a read(2) completes
**			Min = 1 & Time = 0 Means Block Reading wich makes read returns 1
**			byte as soon as it's available
**		c_lflag ==> local mode
**		c_cc 	==> special charcters
*/

int			setup_terminal(struct termios *term)
{
	if (tcgetattr(0, term) < 0)
		return (FALSE);
	term->c_lflag &= ~ECHO;
	term->c_lflag &= ~ICANON;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, term) < 0)
		return (FALSE);
	return (TRUE);
}

/*
** Restore Defaults
**	TODO: Remake This Function by storing the orginal value of the Termios terminal
*/

int			unset_terminal(struct termios *term)
{
	term->c_lflag |= ECHO;
	term->c_lflag |= ICANON;
	if (tcsetattr(0, TCSANOW, term) < 0)
		return (FALSE);
	return (TRUE);
}
