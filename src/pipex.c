/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:50:07 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/02 15:48:09 by luntiet-         ###   ########.fr       */
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

static void	do_op(char **cmd, int fd, char **path)
{
	char	*binary;

	fd = 0; // TODO entfernen wenn benutzt
	binary = search_binary(path, cmd[0]);
	if (!binary)
		exit(EXIT_FAILURE);
}

void	run(int fd, char **argv, int argc, char **path)
{
	char **cmd;
	int	i;

	i = 2;
	while (i < (argc - 1))
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
			exit(EXIT_FAILURE);
		do_op(cmd, fd, path);
		split_free(cmd);
		i++;
	}
}
