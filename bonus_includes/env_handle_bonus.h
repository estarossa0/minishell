/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:37:24 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:38:57 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_HANDLE_H
# define FT_ENV_HANDLE_H
void	init_env();
char	**reverse_env();
t_env	*new_var(char	*full_var);
void	print_env(void);
void	del_env(t_env *env);
#endif
