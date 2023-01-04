/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:50:07 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/04 14:13:21 by luntiet-         ###   ########.fr       */
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
	ft_putendl_fd("command not found", 2);
	exit(EXIT_FAILURE);
}

static void	do_op(char **argv, char **path, int i)
{
	char	*binary;
	char	**cmd;

	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		ft_exit("split");
	binary = search_binary(path, cmd[0]);
	if (cmd[1] != NULL)
	{
		cmd[0] = ft_strjoin_gnl(cmd[0], " ");
		cmd[0] = ft_strjoin_gnl(cmd[0], cmd[1]);
	}
	execve(binary, &cmd[0], NULL);
	free(binary);
	split_free(cmd);
	ft_exit("no executable");
}

int	run(t_fd fd, char **argv, int i, char **path)
{
	pid_t	child;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_exit("pipe");
	child = fork();
	if (child < 0)
		ft_exit("child");
	else if (child == 0)
	{
		dup2(fd.infile, STDIN_FILENO);
		close(fd.infile);
		if (!argv[i + 2])
			dup2(fd.outfile, STDOUT_FILENO);
		else
			dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		do_op(argv, path, i);
	}
	close(pipefd[1]);
	close(fd.infile);
	return (pipefd[0]);
}
