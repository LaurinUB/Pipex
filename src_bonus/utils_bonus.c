/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:40:00 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/09 11:53:27 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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

char	**split_join(char **str)
{
	char	**new;
	int		i;
	char	*tmp;

	if (!str)
		return (NULL);
	new = malloc(3 * sizeof(char *));
	i = 1;
	new[0] = str[0];
	tmp = ft_strdup("");
	while (str[i])
	{
		tmp = ft_strjoin_gnl(tmp, str[i]);
		i++;
		if (str[i])
			tmp = ft_strjoin_gnl(tmp, " ");
	}
	new[1] = tmp;
	new[2] = NULL;
	return (free (str), new);
}

int	outfile(char **argv, int argc)
{
	int	fd;

	fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(argv[argc -1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
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

void	close_pipes(int *pipefd)
{
	close(pipefd[PIPE_IN]);
	close(pipefd[PIPE_OUT]);
}
