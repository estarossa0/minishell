/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:34:07 by arraji            #+#    #+#             */
/*   Updated: 2021/04/07 13:48:38 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H
# include <stdarg.h>
# include "libft.h"
# define NONE	0
# define CRI	128
# define C_T	1
# define S_T	2
# define D_T	4

typedef struct s_printed
{
	unsigned char		type;
	char				*printed;
	char				printed_c;
	unsigned int		index;
	int					fd;
}				t_data;
int				ft_fprintf(int fd, const char *arg1, ...);
unsigned char	check_type(char c);
void			end(char **s1, char **s2);
void			print_char(va_list ar, t_data *data);
int				print_string(va_list ar, t_data *data);
int				print_decimal(va_list ar, t_data *data);
void			ft_reset(t_data *data);
#endif
