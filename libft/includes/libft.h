/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 02:17:00 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 03:20:06 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "get_next_line.h"
# include "ft_fprintf.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif
# define vibe_check write(1, "v", 1);
# define vibe_check2 write(1, "N", 1);
typedef	struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;
void			free_tab(char **tab, int i);
void			ft_bzero(void *tab, size_t num);
void			*ft_memset(void *tab, int valeur, size_t lenght);
void			*ft_memcpy(void *dest, const void *src, size_t num);
void			*ft_memccpy(void *dest, const void *src, int car,
				size_t num);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *str, int value, size_t len);
char			*ft_strchr(const char *str, int velue);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strrchr(const char *str, int value);
void			*ft_calloc(size_t num, size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int car);
int				ft_tolower(int car);
int				ft_isalnum(int car);
int				ft_isascii(int car);
int				ft_isprint(int car);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
void			ft_lstpr_char(t_list *first);
void			ft_lstpr_char_en(t_list *first);
t_list			*ft_lst_test(void);
t_list			*ft_lstdel_index(t_list **list, void fun(t_list *) , int index);
char			*ft_ltoa(unsigned long n);
size_t			ft_number_len(long num);
int				ft_stradd(char **s1, char *s2, int type);
char			*ft_strcpy(char *dest, char *src);
char			*ft_revstr(char *str);
int				ft_end(void **s1, void **s2, int rt);
int				valid_f(char *str);
size_t			ft_tablen(char **tab);
void			pr_tap(char **tab, char *sep);
int				valid_d(char *str);
int				valid_num(char *str, int type);
double			ft_atof(char *str);
int				ft_strcmp(char *s1, char *s2);
size_t			ft_linelen(char const *str, int type);
void			flip_bit(int *data, int bit);
void			standered_error();
/*
** test if a bit is on
*/
#define AND(x, y)		(x & y) == y
/*
** test if a bit if off
*/
#define NAND(x, y)		(x & y) == 0
/*
** useless
*/
#define OR(x, y)		(x | y) == y
/*
** useless
*/
#define NOR(x, y)		(x | y) == 0
/*
** flip a bit on
*/
#define BIT_ON(x, y)	x |= y
/*
** flip a bit off
*/
#define BIT_OFF(x, y)	x &= ~y
#endif
