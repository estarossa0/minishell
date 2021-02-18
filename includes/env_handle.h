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
