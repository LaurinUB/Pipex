/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:25:18 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/10 13:59:31 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	check_null(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) < 1)
			return (0);
		i++;
	}
	return (1);
}

char	*read_file(int fd)
{
	char	*line;
	char	*output;

	line = get_next_line(fd);
	output = ft_strdup("");
	if (!line)
		exit(EXIT_FAILURE);
	while (line)
	{
		output = ft_strjoin_gnl(output, line);
		free(line);
		line = get_next_line(fd);
	}
	return (output);
}

int	here_doc(char **argv)
{
	char	*delimiter;
	char	*tmp;
	int		fd;

	fd = open("here_doc", O_CREAT | O_TRUNC | O_RDWR, 0644);
	delimiter = ft_strjoin(argv[2], "\n");
	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 9);
		tmp = get_next_line(STDIN_FILENO);
		if (ft_strnstr(tmp, delimiter, ft_strlen(delimiter)))
			break ;
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
	}
	close(fd);
	fd = open("here_doc", O_RDONLY);
	return (free(tmp), fd);
}

int	handle_input(int argc, char **argv)
{
	int		fd;

	if (!ft_strncmp(argv[1], "here_doc", 8))
		return (here_doc(argv));
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			perror(argv[1]);
		if (!check_null(argc, argv))
		{
			close(fd);
			ft_exit("no empty arguments allowed");
		}
		return (fd);
	}
	return (fd);
}
