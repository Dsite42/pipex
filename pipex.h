/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:09:27 by cgodecke          #+#    #+#             */
/*   Updated: 2023/04/05 10:56:31 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_cmd_list
{
	char				*program_name;
	int					argc;
	char				**path_split;
	char				*cmd_str;
	char				**cmd_split;
	char				*cmd_path;
	struct s_cmd_list	*next;
}	t_cmd;

char	**awk_split(char const *s, char c);
t_cmd	*init_cmds(int argc, char **argv, char **envp);
void	pipex_error(int shall_exit, char *message,
			int isstrerror, int exit_code);

//list
t_cmd	*pipex_lstnew(char *content);
t_cmd	*pipex_lstlast(t_cmd *lst);
void	pipex_lstadd_back(t_cmd **lst, t_cmd *new);
void	pipex_lstclear(t_cmd *lst);

//of
int		of_fd_printf(int fd, const char *fmt, ...);
char	*of_nstrjoin(int size, char **strs, char *sep);
void	of_free_arr(void **arr);

#endif
