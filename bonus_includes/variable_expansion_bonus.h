/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:38:45 by arraji            #+#    #+#             */
/*   Updated: 2020/12/15 18:38:47 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARIABLE_EXPANSION_H
# define FT_VARIABLE_EXPANSION_H
void	variable_expansion(char *line, int *index, t_command *current);
char	*get_var_value(char *var_name);
#endif
