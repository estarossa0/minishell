/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b-pearl <b-pearl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:39:23 by b-pearl           #+#    #+#             */
/*   Updated: 2020/12/02 18:39:28 by b-pearl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARIABLE_EXPANSION_H
# define FT_VARIABLE_EXPANSION_H
void	variable_expansion(char *line, int *index, t_command *current);
char	*get_var_value(char *var_name);
#endif
