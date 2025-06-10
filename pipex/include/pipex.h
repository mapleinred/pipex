/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:19:50 by xzhang            #+#    #+#             */
/*   Updated: 2023/11/17 10:53:33 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"

int		main(int argc, char **argv, char **envp);
void	pipex(char **argv, char **envp);
void	parent_process(char *argv[], int fileout, char **envp, int *pipefd);
void	child_process(char *infile, char *cmd1, char **envp, int *pipefd);
void	ft_error(char *str);
void	freemem(char **str);
char	*findpath(char *cmd, char **envp);
void	execute(char *cmd, char **envp);

#endif
