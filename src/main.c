/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:55:33 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/02 15:24:34 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		fd;
	char	**path;

	i = 0;
	if (argc < 5)
	{
		ft_putendl_fd("args should be: file1 \"cmd1\" ... \"cmd2\" file2", 2);
		return (EXIT_FAILURE);
	}
	else
	{
		path = get_path(env);
		fd = handle_input(argc, argv);
		run(fd, argv, argc, path);
		split_free(path);
	}
	return (EXIT_SUCCESS);
}
