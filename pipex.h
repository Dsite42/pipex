
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


typedef struct s_cmd_list
{
	char	*program_name;
 	char	*cmd_str;
	char	**cmd_split;
	char	*cmd_path;
	struct	s_cmd_list *next;
} t_cmd;




char	*ft_strjoin_sn(int size, char **strs, char *sep);
void	fto_free_arr(void ** arr);

t_cmd	*pipex_lstnew(char *content);
t_cmd	*pipex_lstlast(t_cmd *lst);
void	pipex_lstadd_back(t_cmd **lst, t_cmd *new);
void	pipex_lstclear(t_cmd *lst);

#endif