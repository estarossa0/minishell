#ifndef NEED_H
# define NEED_H
void	dup_close(int fd1, int fd2);
void	fd_saving(int savefd[2]);
int		is_builtin(char *cmd);
int		find_replace(t_env *var);
void	change_variables(char *old_pwd, bool all);
void	print_export(t_env *list);
int		valid_var(t_env *var);
#endif
