/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:39:11 by arraji            #+#    #+#             */
/*   Updated: 2021/04/07 13:45:09 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HANDLE_H
# define ENV_HANDLE_H
# define SHELL_VAR 0
# define ENV_VAR 1

void	init_env(void);
char	**reverse_env(void);
t_env	*new_var(char	*full_var);
void	print_env(void);
void	del_env(t_env *env);
#endif
