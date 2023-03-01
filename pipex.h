
#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line/get_next_line_bonus.h"



char	*ft_strjoin_sn(int size, char **strs, char *sep);
void	fto_free_arr(void ** arr);

#endif