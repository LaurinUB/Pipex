/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:55:33 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/11 13:42:28 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	sleep_handle(char *cmd)
{
	if (ft_strnstr(cmd, "sleep", 5))
		waitpid(0, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_fd	fd;
	t_input	input;

	i = 2;
	if (!env)
		perror("env");
	if (argc < 5)
		ft_exit("args should be: file1 \"cmd1\" ... \"cmd2\" file2");
	else
	{
		fd.outfile = outfile(argv, argc);
		fd.infile = handle_input(argc, argv);
		input = new_input(argv, env);
		while (i < argc - 1)
		{
			fd.infile = run(fd, input, i);
			sleep_handle(input.argv[i]);
			i++;
		}
		waitpid(0, NULL, 0);
		split_free(input.path);
		close(fd.infile);
		close(fd.outfile);
	}
	return (unlink("here_doc"), EXIT_SUCCESS);
}
