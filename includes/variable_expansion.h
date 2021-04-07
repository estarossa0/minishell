/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:39:23 by b-pearl           #+#    #+#             */
/*   Updated: 2021/04/07 13:46:19 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_EXPANSION_H
# define VARIABLE_EXPANSION_H

void	variable_expansion(char *line, int *index, t_command *current);
char	*get_var_value(char *var_name);
#endif
