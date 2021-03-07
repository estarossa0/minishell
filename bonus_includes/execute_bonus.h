/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:31:39 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:56:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_H
# define FT_EXECUTE_H
# define READ_END	0
# define WRITE_END	1
t_bool	pre_execute(t_command *cmd, int pipefd[2], int savfd[2], int builthin);
void	post_executing(t_command *cmd, int pipefd[2], int savefd[2]);
t_bool	prepare_fd(t_command *cmd, int pipefd[2], int savefd[2]);
void	executing(t_command *cmd, int pipefd[2], int savefd[2]);
t_bool	exec_builthin(t_command *cmd, int builthin);
void	subshell_handle(t_command **cmd, t_pipeline **, int pipefd[2], int savefd[2]);
void	skip_subshell(t_command **cmd, t_pipeline **pipe);
void	finish_all(t_pipeline *pipe);
#endif
