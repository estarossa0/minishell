/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 02:17:00 by arraji            #+#    #+#             */
/*   Updated: 2021/04/07 13:55:05 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "ft_fprintf.h"
# include "get_next_line.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;
typedef char	t_bool;
void			free_tab(char **tab, int i);
void			ft_bzero(void *tab, size_t num);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t num, size_t size);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_toupper(int car);
int				ft_isalnum(int car);
int				ft_isascii(int car);
int				ft_isprint(int car);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstdelone(t_list *lst, void (*del)(void*));
t_list			*ft_lstdel_index(t_list **list, void fun(t_list *), int index);
char			*ft_ltoa(unsigned long n);
int				ft_stradd(char **s1, char *s2, int type);
char			*ft_strcpy(char *dest, char *src);
char			*ft_revstr(char *str);
int				ft_end(void **s1, void **s2, int rt);
size_t			ft_tablen(char **tab);
int				ft_strcmp(char *s1, char *s2);
void			flip_bit(int *data, int bit);
long long		ft_atol(const char *str);
int				and_op(int x, int y);
int				nand_op(int x, int y);
void			bit_on(int *x, int y);
void			bit_off(int *x, int y);
size_t			ft_linelen(char const *str, int type);
#endif
