/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:50:07 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/03 16:36:15 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*search_binary(char **path, char *cmd)
{
	char	*absolute_path;
	int		i;

	i = 0;
	while (path[i])
	{
		absolute_path = ft_strjoin(path[i], "/");
		absolute_path = ft_strjoin_gnl(absolute_path, cmd);
		if (access(absolute_path, X_OK) >= 0)
			return (absolute_path);
		free(absolute_path);
		i++;
	}
	return (NULL);
}

static void	do_op(char **argv, char **path, int i)
{
	char	*binary;
	char	**cmd;

	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		ft_exit("split");
	binary = search_binary(path, cmd[0]);
	if (!binary)
		exit(EXIT_FAILURE);
	if (cmd[1] != NULL)
	{
		cmd[0] = ft_strjoin_gnl(cmd[0], " ");
		cmd[0] = ft_strjoin_gnl(cmd[0], cmd[1]);
	}
	execve(binary, &cmd[0], NULL);
	free(binary);
	split_free(cmd);
}

void	run(int fd, char **argv, int argc, char **path)
{
	char	*file;
	pid_t	child;
	int		pipefd[2];
	int		i;

	i = 2;
	argc = 5;
	file = read_file(fd);
	close(fd);
	if (pipe(pipefd))
		ft_exit("pipe");
	child = fork();
	if (child == -1)
		ft_exit("fork");
	if (child == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		do_op(argv, path, 2);
	}
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	do_op(argv, path, 3);
	close(pipefd[0]);
	close(pipefd[1]);
	//while (i < (argc - 1))
	//{
	//	do_op(argv, path, i);
	//	i++;
	//}
}
