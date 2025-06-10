/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:44:04 by xzhang            #+#    #+#             */
/*   Updated: 2023/11/13 15:26:05 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
	{
		pipex(argv, envp);
	}
	else
	{
		ft_error("\033[31m how to use./pipex <infile> <cmd1> <cmd2> <outfile>");
	}
	return (0);
}

void	child_process(char *infile, char *cmd1, char **envp, int *pipefd)
{
	int		filein;

	filein = open(infile, O_RDONLY, 0777);
	if (filein == -1)
		ft_error("\033[31mFailed to open input file");
	dup2(filein, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	execute(cmd1, envp);
}

void	parent_process(char *argv[], int fileout, char **envp, int *pipefd)
{
	if (fileout == -1)
		ft_error("\033[31mFailed to open input file");
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(pipefd[1]);
	execute(argv[3], envp);
}

void	pipex(char **argv, char **envp)
{
	int	pipefd[2];
	int	pid;
	int	fileout;

	if (pipe(pipefd) == -1)
		ft_error("\033[31mPipe creation failed");
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pid = fork();
	if (pid == -1)
		ft_error("\033[31mFork failed");
	if (pid == 0)
		child_process(argv[1], argv[2], envp, pipefd);
	else
	{
		waitpid(pid, NULL, WNOHANG);
		parent_process(argv, fileout, envp, pipefd);
	}
}
/*pid == 0 child process else is parent process */
