/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:34:07 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 16:16:33 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FT_FPRINTF_H
# define FT_FT_FPRINTF_H
# include <stdarg.h>
# include "libft.h"
# define NONE	0
# define POINT	2
# define AST	4
# define ZE_FL	8
# define LE_ALI	16
# define WIDTH	32
# define PRE	64
# define CRI	128
# define C_T	1
# define S_T	2
# define P_T	3
# define D_T	4
# define U_T	5
# define X_T	6
# define XX_T	7
# define PERC	8

typedef	struct	s_printed
{
	unsigned char		type;
	unsigned char		flag;
	char				*printed;
	char				fill_char;
	char				printed_c;
	int					size_rt;
	int					width;
	int					precision;
	int					pr_size;
	unsigned int		index;
	int					fd;
}				t_data;
int				ft_fprintf(int fd, const char *arg1, ...);
unsigned char	check_type(char c);
void			end(char **s1, char **s2);
void			c_type(va_list ar, t_data *data);
int				s_type(va_list ar, t_data *data);
int				p_type(va_list ar, t_data *data);
int				d_type(va_list ar, t_data *data);
int				d_type_utils(t_data *data, int neg);
int				u_type(va_list ar, t_data *data);
int				u_type_utils(t_data *data, int len);
int				x_type(va_list ar, t_data *data);
int				x_type_utils(t_data *data, int len);
void			print_char(va_list ar, t_data *data);
int				print_string(va_list ar, t_data *data);
void			print_string_utils(t_data *data, int type);
int				print_corder(va_list ar, t_data *data);
void			print_corder_utils(t_data *data, int type);
int				print_decimal(va_list ar, t_data *data);
int				print_unsigned(va_list ar, t_data *data);
int				print_hexa(va_list ar, t_data *data);
void			print_perc(t_data *data);
void			check_flag(const char *arg1, va_list ar, t_data *data);
char			*ft_to_hex(unsigned long hl, int type);
void			ft_reset(t_data *data);
#endif
