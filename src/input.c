/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:25:18 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/02 14:20:58 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
		file_error();
	if (!check_null(argc, argv))
	{
		ft_putendl_fd("no empty arguments allowed", 2);
		close(fd);
		exit(EXIT_FAILURE);
	}
	return	(fd);
}
