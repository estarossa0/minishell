/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:39:50 by ikhadem           #+#    #+#             */
/*   Updated: 2020/12/30 08:12:39 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINES_H
# define FT_DEFINES_H

# ifndef TRUE
#  define TRUE 0
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define K_RETURN 127

/*
**	im ==> string to inter insert mode
**	ic ==> string to insert char
**	ip ==> string to output char padding if needed
**	ei ==> string to exit insert mode
*/

typedef	struct	s_ichar
{
	char		*im;
	char		*ic;
	char		*ip;
	char		*ei;
}				t_ichar;

/*
**	dm ==> string to inter delete mode
**	dc ==> string to delete char
**	ed ==> string to exit delete mode
*/

typedef	struct	s_dchar
{
	char		*dc;
	char		*dm;
	char		*ed;
}				t_dchar;

/*
**	cm ==> string to move the cursor to pos(l, c)
**	le ==> string to move cursor left
**	nd ==> string to move cursor right
**	ho ==> string to move cursor to home pos
**	up ==> string to move up one row
**	dw ==> string to move down one row (beware if wrapping exists)
*/

typedef struct	s_cmotion
{
	char		*cm;
	char		*le;
	char		*ri;
	char		*ho;
	char		*up;
	char		*dw;
}				t_cmotion;

typedef	struct	s_capability
{
	t_ichar		insert_char;
	t_dchar		delete_char;
	t_cmotion	cursor;
}				t_capability;

typedef	struct	s_cmd
{
	char			*line;
	int				index;
	int				length;
	int				buff_size;
	t_capability	cap;
}				t_cmd;

#endif