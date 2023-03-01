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

char	**create_execve_argv(char **argv)
{
	char	**needed_argvs;
	char	**cmd_split;

	cmd_split = ft_split(*(argv +1), ' ');
	needed_argvs = (char **) malloc(sizeof(char *) * 3);
	needed_argvs[0] = *argv;
	needed_argvs[1] = cmd_split[0];
	needed_argvs[2] = NULL;
	fto_free_arr((void **)(cmd_split+1));
	
	//exit(0);
	return (needed_argvs);
}

char	*get_path_cmd(char **argv)
{
	int		fork_return;
	int		pipefd[2];
	char	*args_1[] = {"a.out", "ls", NULL};
	char	**path_argv;
	char 	*new_line;

	path_argv = create_execve_argv(argv);
	
	//printf("path_argv1:%s\n", ft_strjoin_sn(3, path_argv, " "));
	pipe(pipefd);
	fork_return = fork();
	if (fork_return == -1)
		perror("fork error");
	else if (fork_return == 0)
	{
		dup2 (pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve("/usr/bin/which", (char * const *)path_argv, NULL);
	}
	else
	{
		wait(NULL);
		fto_free_arr((void **)path_argv+1);
		new_line = get_next_line(pipefd[0]);
		new_line[ft_strlen(new_line) - 1] = '\0';
		return (new_line);
	}
}

int	main(int argc, char **argv)
{
	int	pipefd[2];
	int	 fd;
	char buf[10001];
	char *args_1[] = { "pipex", "-la", NULL};
	char	*path_cmd;

	//printf("ERROR:%s\n", );
	path_cmd = get_path_cmd(argv);
	
//execve("/usr/bin/grep", argv, NULL);
//exit(0);
	pipe(pipefd);
	if (fork() == 0)
	{
		dup2 (pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve((const char *) path_cmd, args_1, NULL);
	}
	else
	{
		wait(NULL);
		free(path_cmd);
		dup2 (pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		fd = open("result.txt", O_RDWR);
		dup2 (fd, STDOUT_FILENO);
		close(fd);



		//dup2 (pipefd[0], STDIN_FILENO);
		//read(fd[0], buf, 10000);
execlp("wc", "wc", "-w", NULL);
		//execve("/usr/bin/grep", argv, NULL);
		//read(pipefd[0], buf, 10000);
		//buf[10000] = '\0';
		//printf("Hallo:%s\n", buf);
	}
}
