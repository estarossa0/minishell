/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:39:11 by arraji            #+#    #+#             */
/*   Updated: 2021/03/07 15:42:07 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_HANDLE_H
# define FT_ENV_HANDLE_H
# define SHELL_VAR 0
# define ENV_VAR 1

void	init_env();
char	**reverse_env();
t_env	*new_var(char	*full_var);
void	print_env(void);
void	del_env(t_env *env);
#endif
