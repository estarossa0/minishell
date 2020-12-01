#include "libft.h"

void	standered_error()
{
	ft_fprintf(2, "%s\n" , strerror(errno));
	exit(errno);
}
