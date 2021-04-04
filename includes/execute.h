/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:31:39 by arraji            #+#    #+#             */
/*   Updated: 2021/04/04 14:12:36 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_H
# define FT_EXECUTE_H
# define READ_END	0
# define WRITE_END	1

t_bool	pre_execute(t_command *cmd, int pipefd[2], int savfd[2], int builthin);
void	executing(t_command *cmd, int pipefd[2], int savefd[2]);
t_bool	exec_builthin(t_command *cmd, int builthin);
void	finish_all(t_pipeline *pipe);
t_bool		b_echo(t_command *cmd);
t_bool		b_cd(t_command *cmd);
t_bool		b_pwd(t_command *cmd);
t_bool		b_export(t_command *cmd);
#endif
