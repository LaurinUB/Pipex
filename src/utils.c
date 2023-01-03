/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:40:00 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/03 11:48:08 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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

char	**get_path(char **env)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			tmp = ft_strtrim(env[i], "PATH=");
			path = ft_split(tmp, ':');
			return (free(tmp), path);
		}
		i++;
	}
	return (NULL);
}
