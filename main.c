/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:21:13 by chris             #+#    #+#             */
/*   Updated: 2023/03/01 19:42:56 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_execve_argv(t_cmd *cmd_list)
{
	char	**needed_argvs;

	needed_argvs = (char **) malloc(sizeof(char *) * 3);
	needed_argvs[0] = cmd_list->program_name;
	needed_argvs[1] = cmd_list->cmd_split[0];
	needed_argvs[2] = NULL;
	return (needed_argvs);
}

void	pipex_error(char *message, int isperror, int exit_code)
{
	if (isperror == 1)
	{
		//printf("Error code:%i ", errno);
		perror(message);
	}
	else
		printf("%s\n", message);  // get next line und printf in ftlib integrieren
	exit(exit_code);
}

void	split_path(t_cmd *cmd_list, char **envp)
{
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			cmd_list->path_split = ft_split(*envp, ':');
			break ;
		}
		envp = envp + 1;
	}
}

char	*get_path_cmd(t_cmd *cmd_list, char **envp)
{
	char	*path_cmd;
	int		i;
	char	*to_join[2];

	i = 0;
	path_cmd = NULL;
	to_join[1] = (cmd_list->cmd_split)[0];
	split_path(cmd_list, envp);
	while ((cmd_list->path_split)[i] != NULL)
	{
		to_join[0] = (cmd_list->path_split)[i];
		path_cmd = ft_strjoin_sn(2, to_join, "/");
		if (access(path_cmd, F_OK) == 0)
			break ;
		else
		{
			free(path_cmd);
			path_cmd = NULL;
		}
		i++;
	}
	//if (path_cmd == NULL)
	//	pipex_error("Command not found", 1, errno);
	return (path_cmd);
}

t_cmd	*init_cmds(int argc, char **argv, char **envp)
{
	int		i;
	t_cmd	*cmd_list;
	t_cmd	*new_node;

	i = 2;
	cmd_list = NULL;

	if (argc < 5)
		pipex_error("Not enough input arguments", 0, 5);
	while(i <= argc - 2) // Noch ändern da 2 dateinamen in den argumenten
	{
		new_node = pipex_lstnew(*(argv + i));
		new_node->program_name = ft_strdup(*argv);
		new_node->cmd_split = ft_split(new_node->cmd_str, ' ');
		new_node->cmd_path = get_path_cmd(new_node, envp);

		//printf("fuck:%s\n", new_node->cmd_path);
		pipex_lstadd_back(&cmd_list, new_node);
		i++;
	}
	return (cmd_list);
}

void	run_cmds(int argc, char **argv, char **envp, t_cmd *cmd_list)
{
	int		pipefd[2];
	int		fd_in;
	int		fd_out;
	int		fd_dup[]={0,0};
	char	*path_cmd;
	pid_t	pid;
	int		stat_loc;

	path_cmd = cmd_list->cmd_path;
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		fd_dup[0] = dup2 (pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		fd_in = open(argv[1], O_RDONLY);
		fd_dup[1] = dup2 (fd_in, STDIN_FILENO);
		close(fd_in);
		//printf("wasLos:%s\n", path_cmd);
	//if (path_cmd != NULL)
		if (execve((const char *) path_cmd, cmd_list->cmd_split, envp) == -1)
			pipex_error("execve child error", 1, errno);
	}
	else
	{
		//wait(NULL);
		
		waitpid(pid, &stat_loc, WNOHANG);
		//exit(0);
		//printf("stat_log:%i\n", stat_loc);
		//exit(0);
		//close(fd_dup[0]);
		//close(fd_dup[1]);
		fd_dup[0] = dup2 (pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644 );
		if (fd_out == -1)
			pipex_error("Could not open file", 1, errno);
		fd_dup[1] = dup2 (fd_out, STDOUT_FILENO);
		close(fd_out);
		if (execve((const char *) cmd_list->next->cmd_path, cmd_list->next->cmd_split, envp) == -1)
			pipex_error("execve parent error", 1, errno);
	}
}	

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd_list;

	cmd_list = init_cmds(argc, argv, envp);
	run_cmds(argc, argv, envp, cmd_list);
	//pipex_lstclear(cmd_list);
	//printf("ERROR:%s | %s\n", cmd_list->cmd_str, cmd_list->next->cmd_split[0]);
	//exit(0);
	return (0);
}
