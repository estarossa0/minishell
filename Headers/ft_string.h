/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 08:02:52 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/30 08:31:49 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# ifndef CMD_MAX_LEN
#  define CMD_MAX_LEN 2048
# endif

# include <string.h>
# include "termcaps.h"
# include "ft_defines.h"

void			str_add(t_cmd *cmd, int c);

#endif