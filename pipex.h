/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:09:27 by cgodecke          #+#    #+#             */
/*   Updated: 2023/03/25 19:06:14 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_fprintf/ft_fprintf.h"
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line/get_next_line_bonus.h"
# include <errno.h>

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

char	*ft_strjoin_sn(int size, char **strs, char *sep);
void	fto_free_arr(void **arr);
t_cmd	*pipex_lstnew(char *content);
t_cmd	*pipex_lstlast(t_cmd *lst);
void	pipex_lstadd_back(t_cmd **lst, t_cmd *new);
void	pipex_lstclear(t_cmd *lst);
char	**awk_split(char const *s, char c);
t_cmd	*init_cmds(int argc, char **argv, char **envp);
void	pipex_error(int shall_exit, char *message,
			int isstrerror, int exit_code);
#endif
