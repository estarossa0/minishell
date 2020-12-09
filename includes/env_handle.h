#ifndef FT_ENV_HANDLE_H
# define FT_ENV_HANDLE_H
void	init_env();
char	**reverse_env();
t_env	*new_var(char	*full_var);
void	print_env(void);
void	del_env(t_env *env);
#endif
