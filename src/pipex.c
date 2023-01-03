/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:50:07 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/03 11:26:00 by luntiet-         ###   ########.fr       */
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

static void	do_op(char **cmd, char **path)
{
	char	*binary;

	binary = search_binary(path, cmd[0]);
	if (!binary)
		exit(EXIT_FAILURE);
	if (cmd[1] != NULL)
		cmd[0] = ft_strjoin_gnl(cmd[0], cmd[1]);
	execve(binary, &cmd[0], NULL);
}

void	run(int fd, char **argv, int argc, char **path)
{
	char	**cmd;
	//char	*file;
	int		i;

	i = 2;
	//file = read_file(fd);
	fd = 0; //TODO remve when used
	while (i < (argc - 1))
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
			exit(EXIT_FAILURE);
		do_op(cmd, path);
		split_free(cmd);
		i++;
	}
}
