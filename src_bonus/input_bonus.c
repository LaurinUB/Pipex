/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:25:18 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/05 19:19:25 by luntiet-         ###   ########.fr       */
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

int	handle_input(int argc, char **argv)
{
	int	fd;

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
