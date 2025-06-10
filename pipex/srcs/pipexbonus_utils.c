/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexbonus_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:07:44 by xzhang            #+#    #+#             */
/*   Updated: 2023/11/22 18:22:43 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/* error function*/
void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

/*free function*/
void	freemem(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

void	cmds(char *cmd, char *env[])
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_error("Pipe error in cmds");
	pid = fork();
	if (pid == -1)
		ft_error("Fork error in cmds");
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execute(cmd, env);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
	}
}

char	*findpath(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*partp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		partp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(partp, cmd);
		free(partp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	freemem(paths);
	return (0);
}

void	execute(char *cmd, char **envp)
{
	char	**cmdargs;
	int		i;
	char	*path;

	i = -1;
	cmdargs = ft_split(cmd, ' ');
	path = findpath(cmdargs[0], envp);
	if (!path)
	{
		while (cmdargs[++i])
			freemem(cmdargs);
		ft_error("\033[31mExecuteable path not found OvO ");
	}
	if (execve(path, cmdargs, envp) == -1)
		ft_error("\033[31mExecve function failed OvO");
}
/*
execve system call is successful, it will replace the current process /
addindex with the new program, and the subsequent code will not be executed. /
In the provided code:
If execve succeeds, the code inside the if block (ft_error) will not be /
executed. The reason is that execve only returns if there is an error; /
otherwise, it replaces the current process with the specified program.
So, if execve is successful, there won't be any output from the ft_error /
function or any other code inside the if block. The absence of output from /
ft_error indicates that the execution of the specified command was successful, /
and the new program is running in the current process. If there's an issue with /
the execution (e.g., the specified executable couldn't be found or there was /
another problem), execve returns -1, the if condition is true, and the /
ft_error function is called to display an error message before the /
program exits.
*/
