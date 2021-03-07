/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:39:28 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEED_H
# define NEED_H

void	dup_close(int fd1, int fd2);
void	fd_saving(int savefd[2]);
int		is_builtin(char *cmd);
int		find_replace(t_env *var);
void	change_variables(char *old_pwd, t_bool all);
void	print_export(t_env *list);
#endif
