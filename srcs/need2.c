/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:02:08 by arraji            #+#    #+#             */
/*   Updated: 2021/04/06 16:02:38 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	change_variables2(char *pwd, t_bool all)
{
	t_env	*new;

	if (pwd)
	{
		g_all->pwd = ft_strdup(pwd);
		ft_stradd(&pwd, "PWD=", -1);
		new = new_var(pwd);
		if (!find_replace(new))
		{
			if (all == -1)
				ft_lstadd_back((t_list **)&g_all->env, (void *)new);
			else
				ft_lstdel_index((t_list **)&new,
					(void (*)(t_list *))del_env, 0);
		}
		free(pwd);
	}
}

void	change_variables(char *old_pwd, t_bool all)
{
	t_env	*new;
	char	*pwd;

	if (all == TRUE)
	{
		ft_stradd(&old_pwd, "OLDPWD=", -1);
		new = new_var(old_pwd);
		if (!find_replace(new))
			ft_lstdel_index((t_list **)&new, (void (*)(t_list *))del_env, 0);
		free(old_pwd);
	}
	pwd = getcwd(NULL, 0);
	change_variables2(pwd, all);
}
