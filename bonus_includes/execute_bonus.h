/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b-pearl <b-pearl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:31:39 by arraji            #+#    #+#             */
/*   Updated: 2020/12/02 18:38:21 by b-pearl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_H
# define FT_EXECUTE_H
# define READ_END	0
# define WRITE_END	1
bool	pre_execute(t_command *cmd, int pipefd[2], int savfd[2], int builthin);
bool	executing(t_command *cmd, int pipefd[2], int savefd[2]);
bool	exec_builthin(t_command *cmd, int builthin);
#endif
