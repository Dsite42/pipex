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

char	*get_path_cmd(t_cmd *cmd_list)
{
	int		fork_return;
	int		pipefd[2];
	char	**path_argv;
	char 	*new_line;

	path_argv = create_execve_argv(cmd_list);
	//printf("path_argv1:%s\n", ft_strjoin_sn(10, path_argv, " "));
	pipe(pipefd);
	fork_return = fork();
	if (fork_return == -1)
		perror("fork error");
	else if (fork_return == 0)
	{
		dup2 (pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve("/usr/bin/which", (char * const *)path_argv, NULL); // wenn befehl nicht existent, dann hängt er hier
	}
	else
	{
		wait(NULL);
		free(path_argv);
		new_line = get_next_line(pipefd[0]);
		new_line[ft_strlen(new_line) - 1] = '\0';
		return (new_line);
	}
}


t_cmd	*init_cmds(int argc, char **argv)
{
	int		i;
	t_cmd	*cmd_list;
	t_cmd	*new_node;

	i = 2;
	while(i <= argc - 2) // Noch ändern da 2 dateinamen in den argumenten
	{
		new_node = pipex_lstnew(*(argv + i));
		new_node->program_name = ft_strdup(*argv);
		new_node->cmd_split = ft_split(new_node->cmd_str, ' ');
		new_node->cmd_path = get_path_cmd(new_node);

		//printf("fuck:%s\n", new_node->cmd_path);
		pipex_lstadd_back(&cmd_list, new_node);
		i++;
	}
	return (cmd_list);
}



int	main(int argc, char **argv)
{
	int		pipefd[2];
	int		fd_in;
	int		fd_out;
	char buf[10001];
	char	*path_cmd;
	t_cmd	*cmd_list;

	cmd_list = init_cmds(argc, argv);
	//printf("ERROR:%s | %s\n", cmd_list->cmd_str, cmd_list->next->cmd_split[0]);
	//exit(0);
	path_cmd = cmd_list->cmd_path;
	
//execve("/usr/bin/grep", argv, NULL);
//exit(0);
	pipe(pipefd);
	if (fork() == 0)
	{
		dup2 (pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		fd_in = open(argv[1], O_RDONLY);
		dup2 (fd_in, STDIN_FILENO);
		close(fd_in);
		execve((const char *) path_cmd, cmd_list->cmd_split, NULL);
	}
	else
	{
		wait(NULL);
		free(path_cmd);
		dup2 (pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		fd_out = open(argv[argc - 1], O_CREAT | O_RDWR, 0644 );
		dup2 (fd_out, STDOUT_FILENO);
		close(fd_out);
		execve((const char *) cmd_list->next->cmd_path, cmd_list->next->cmd_split, NULL);

//execlp("wc", "wc", "-w", NULL);
		//execve("/usr/bin/grep", argv, NULL);
		//read(0, buf, 10000);
		//buf[10000] = '\0';
		//printf("Hallo:%s\n", buf);
	}
}
