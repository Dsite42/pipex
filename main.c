/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:21:13 by chris             #+#    #+#             */
/*   Updated: 2023/04/05 11:28:55 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_cmd *cmd_list, char **argv, char **envp, int *pipefd)
{
	int	fd_dup[2];
	int	fd_in;

	fd_dup[0] = dup2 (pipefd[1], STDOUT_FILENO);
	if (fd_dup[0] == -1)
		pipex_error(1, "dup2 error", 1, errno);
	close(pipefd[0]);
	close(pipefd[1]);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		pipex_error(1, "input:", 1, errno);
	fd_dup[1] = dup2 (fd_in, STDIN_FILENO);
	if (fd_dup[1] == -1)
		pipex_error(1, "dup2 error", 1, errno);
	close(fd_in);
	if (cmd_list->cmd_path != NULL)
	{
		if (execve((const char *) cmd_list->cmd_path,
				cmd_list->cmd_split, envp) == -1)
			pipex_error(0, "execve child error.", 1, errno);
	}
}

void	parent(t_cmd *cmd_list, char **argv, char **envp, int *pipefd)
{
	int	fd_dup[2];
	int	fd_out;

	fd_dup[0] = dup2 (pipefd[0], STDIN_FILENO);
	if (fd_dup[0] == -1)
		pipex_error(1, "dup2 error", 1, errno);
	close(pipefd[0]);
	close(pipefd[1]);
	fd_out = open(argv[cmd_list->argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out == -1)
		pipex_error(1, "Could not open file", 1, errno);
	fd_dup[1] = dup2 (fd_out, STDOUT_FILENO);
	if (fd_dup[1] == -1)
		pipex_error(1, "dup2 error", 1, errno);
	close(fd_out);
	if (cmd_list->next->cmd_path != NULL)
	{
		if (execve((const char *) cmd_list->next->cmd_path,
				cmd_list->next->cmd_split, envp) == -1)
			pipex_error(1, "execve parent error", 1, errno);
	}
	else
		exit (127);
}

void	run_cmds(char **argv, char **envp, t_cmd *cmd_list)
{
	int		pipefd[2];
	pid_t	pid;
	int		stat_loc;

	if (pipe(pipefd) == -1)
		pipex_error(1, "error while creating pipe", 1, errno);
	pid = fork();
	if (pid == -1)
		pipex_error(1, "error while forking", 1, errno);
	if (pid == 0)
		child(cmd_list, argv, envp, pipefd);
	waitpid(pid, &stat_loc, WNOHANG);
	if (WIFEXITED(stat_loc) && WEXITSTATUS(stat_loc) != 0)
		exit(WEXITSTATUS(stat_loc));
	if (pid > 0)
		parent(cmd_list, argv, envp, pipefd);
}	

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd_list;
	pid_t	pid;
	int		stat_loc;

	cmd_list = init_cmds(argc, argv, envp);
	pid = fork();
	if (pid == -1)
		pipex_error(1, "error while forking", 1, errno);
	if (pid == 0)
	{
		run_cmds(argv, envp, cmd_list);
	}
	waitpid(pid, &stat_loc, 0);
	if (pid > 0)
	{
		if (cmd_list != NULL)
			pipex_lstclear(cmd_list);
		if (WIFEXITED(stat_loc) && WEXITSTATUS(stat_loc) != 0)
			exit(WEXITSTATUS(stat_loc));
	}
	return (0);
}
