/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:17:18 by xzhang            #+#    #+#             */
/*   Updated: 2023/11/28 13:15:53 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	ft_error(char *str);
void	freemem(char **str);
void	cmds(char *cmd, char *env[]);
void	execute(char *cmd, char **envp);
void	limiter(char *limiter, int *fd);
void	heredoc(char *argv[], int argc);
void	infile(char *argv[]);
char	*findpath(char *cmd, char **envp);
int		main(int argc, char *argv[], char *env[]);

#endif
