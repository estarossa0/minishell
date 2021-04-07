/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:36:02 by rbougssi          #+#    #+#             */
/*   Updated: 2021/04/07 13:45:53 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "minishell.h"

int			readline(char **line, t_hist *hist);
t_hlist		*dlist_push_back(t_hlist **lst, t_hlist *new);
void		del(int size);
void		hist_reset(t_hlist *head, int all);
void		hist_init(t_hlist *head, t_hlist **end);
#endif
