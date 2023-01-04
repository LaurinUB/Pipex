/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:55:33 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/04 14:09:23 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_fd	fd;
	char	**path;

	i = 2;
	if (argc != 5)
		ft_exit("args should be: file1 \"cmd1\" ... \"cmd2\" file2");
	else
	{
		fd.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		path = get_path(env);
		fd.infile = handle_input(argc, argv);
		while (i < argc - 1)
		{
			fd.infile = run(fd, argv, i, path);
			i++;
		}
		waitpid(0, NULL, 0);
		split_free(path);
		close(fd.infile);
		close(fd.outfile);
	}
	//system("leaks pipex");
	return (EXIT_SUCCESS);
}
