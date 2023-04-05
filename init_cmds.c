/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:15:24 by cgodecke          #+#    #+#             */
/*   Updated: 2023/04/05 18:59:44 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_std_path(void)
{
	return ("PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin"
	);
}

void	split_path(t_cmd *cmd_list, char **envp)
{
	if (*envp == NULL)
		cmd_list->path_split = ft_split(get_std_path(), ':');
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			cmd_list->path_split = ft_split(*envp + 5, ':');
			break ;
		}
		envp = envp + 1;
	}
}

void	search_accessable_path(t_cmd *cmd_list, char **to_join, char **path_cmd)
{
	int	i;

	i = 0;
	while ((cmd_list->path_split)[i] != NULL)
	{
		to_join[0] = (cmd_list->path_split)[i];
		*path_cmd = of_nstrjoin(2, to_join, "/");
		if (access(*path_cmd, F_OK) == 0)
			break ;
		else
		{
			free(*path_cmd);
			*path_cmd = NULL;
		}
		i++;
	}
}

char	*get_path_cmd(t_cmd *cmd_list, char **envp)
{
	char	*path_cmd;
	char	*to_join[2];
	char	*error_message;

	path_cmd = NULL;
	if (access((cmd_list->cmd_split)[0], F_OK) == 0)
		return (ft_strdup((cmd_list->cmd_split)[0]));
	to_join[1] = (cmd_list->cmd_split)[0];
	split_path(cmd_list, envp);
	search_accessable_path(cmd_list, to_join, &path_cmd);
	if (path_cmd == NULL)
	{
		error_message = ft_strjoin((cmd_list->cmd_split)[0],
				": command not found");
		pipex_error(0, error_message, 0, 127);
		free(error_message);
	}
	return (path_cmd);
}

t_cmd	*init_cmds(int argc, char **argv, char **envp)
{
	int		i;
	t_cmd	*cmd_list;
	t_cmd	*new_node;

	i = 2;
	cmd_list = NULL;
	if (argc != 5)
		pipex_error(1, "Invalid amount of input arguments", 0, 5);
	while (i <= argc - 2)
	{
		new_node = pipex_lstnew(*(argv + i));
		new_node->argc = argc;
		new_node->program_name = ft_strdup(*argv);
		if (ft_strncmp("awk ", new_node->cmd_str, 4) == 0)
			new_node->cmd_split = awk_split(new_node->cmd_str, ' ');
		else
			new_node->cmd_split = ft_split(new_node->cmd_str, ' ');
		new_node->cmd_path = get_path_cmd(new_node, envp);
		pipex_lstadd_back(&cmd_list, new_node);
		i++;
	}
	return (cmd_list);
}
