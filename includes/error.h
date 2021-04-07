/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:06:00 by arraji            #+#    #+#             */
/*   Updated: 2021/04/07 13:45:29 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define E_STANDARD	1
# define E_SYNTAX	2
# define E_FILE		3
# define E_NOCMD	4
# define E_WPATH	5
# define E_ISDIR	6
# define E_ARGS		7
# define E_CD		8
# define E_NOT_VAL	9
# define E_EXIT_ARG	10
# define E_CD_HOME	11
# define E_NOTERM 12

int		error(int error, int exit_value, char *need);
int		freak_out(int bits, char *line, int index);
void	chill(int *bits);
#endif
