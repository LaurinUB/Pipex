/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:50:07 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/06 17:41:46 by luntiet-         ###   ########.fr       */
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
		if (access(absolute_path, F_OK) >= 0)
			return (absolute_path);
		free(absolute_path);
		i++;
	}
	ft_putendl_fd("command not found", 2);
	exit(EXIT_FAILURE);
}

static void	do_op(t_input input, int i)
{
	char	*binary;
	char	**cmd;

	binary = input.argv[i];
	if (ft_strchr(input.argv[i], '\t'))
		cmd = ft_split(input.argv[i], '\t');
	else
		cmd = ft_split(input.argv[i], ' ');
	if (!cmd)
		ft_exit("split");
	if (access(input.argv[i], X_OK) < 0)
		binary = search_binary(input.path, cmd[0]);
	execve(binary, cmd, input.env);
	free(binary);
	split_free(cmd);
	ft_exit("no executable");
}

int	run(t_fd fd, t_input input, int i)
{
	pid_t	child;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_exit_close("pipe", fd, input.path);
	child = fork();
	if (child < 0)
		ft_exit_close("child", fd, input.path);
	else if (child == 0)
	{
		if (fd.infile < 0 || fd.outfile < 0)
			exit(EXIT_FAILURE);
		dup2(fd.infile, STDIN_FILENO);
		close(fd.infile);
		if (!input.argv[i + 2])
			dup2(fd.outfile, STDOUT_FILENO);
		else
			dup2(pipefd[PIPE_OUT], STDOUT_FILENO);
		close_pipes(pipefd);
		do_op(input, i);
	}
	close(pipefd[PIPE_OUT]);
	close(fd.infile);
	return (pipefd[PIPE_IN]);
}
