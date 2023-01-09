/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:25:18 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/09 16:24:51 by luntiet-         ###   ########.fr       */
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

int	handle_input(int argc, char **argv)
{
	int	fd;

	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		fd = open("here_doc", O_CREAT | O_TRUNC | O_RDWR, 0777);
		char	buf[1];
		char	*delimiter;
		char	*tmp;

		delimiter = ft_strjoin(argv[2], "\n");
		tmp = ft_strdup("");
		while (read(STDIN_FILENO, buf, sizeof(buf)) > 0)
		{
			if (ft_strnstr(tmp, delimiter, ft_strlen(tmp)))
				break;
			tmp = ft_strjoin_gnl(tmp, buf);
		}
		write(fd, tmp, ft_strlen(tmp));
		return (free(tmp), fd);
	}
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

t_input	new_input(char **argv, char **env)
{
	t_input	input;

	input.path = get_path(env);
	input.argv = argv;
	input.env = env;
	return (input);
}

char	**split_on_whitespace(char *argv)
{
	if (ft_strchr(argv, '\t'))
		return (ft_split(argv, '\t'));
	else
		return (ft_split(argv, ' '));
}
