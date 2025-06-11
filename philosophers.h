#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "limits.h"
# include "libft.h"

# define SUCCESS 0
# define FAIL 1

# define ERR_AC 1

# define MSG_AC "Error !\n4 arguments required\n"

void	ft_error(char *err_msg, int err_nb);

#endif