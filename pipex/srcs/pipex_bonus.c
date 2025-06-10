/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:44:04 by xzhang            #+#    #+#             */
/*   Updated: 2023/11/22 18:21:45 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	limiter(char *limiter, int *fd)
{
	char	*input;

	while (1)
	{
		input = get_next_line(STDIN_FILENO);
		if (!input)
			ft_error("Failed receive heredoc input");
		if ((ft_strncmp(input, limiter, ft_strlen(limiter)) == 0) 
			&& (ft_strlen(input) - 1 == ft_strlen(limiter)))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		write(fd[1], input, ft_strlen(input));
		free(input);
	}
	close(fd[0]);
}

void	heredoc(char *argv[], int argc)
{
	int	fd[2];
	int	pid;

	if (argc < 6)
		ft_error("Too litte argument");
	if (pipe(fd) == -1)
		ft_error("Pipe error in heredoc");
	pid = fork();
	if (pid == -1)
		ft_error("Fork error in heredoc");
	if (pid == 0)
		limiter(argv[2], fd);
	else
	{
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
	}
}

void	infile(char *argv[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error("Failed to open input file");
	dup2(infile, STDIN_FILENO);
}

static int	x(int argc, char *argv[], int i)
{
	int	outfile;

	if (i == 3)
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (outfile);
}

int	main(int argc, char *argv[], char *env[])
{
	int	outfile;
	int	i;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			heredoc(argv, argc);
			i = 3;
		}
		else
		{
			infile(argv);
			i = 2;
		}
		outfile = x(argc, argv, i);
		while (i < argc - 2)
			cmds(argv[i++], env);
		if (outfile == -1)
			ft_error("can not open output file");
		dup2(outfile, STDOUT_FILENO);
		execute(argv[argc - 2], env);
	}
	ft_error("Too little arguments");
}
