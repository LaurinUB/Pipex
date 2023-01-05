/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:58:59 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/05 19:20:03 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_HH

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef enum e_pipefd {PIPE_IN, PIPE_OUT}	t_pipefd;

typedef struct s_fd
{
	int		infile;
	int		outfile;
}	t_fd;

typedef struct s_input
{
	char	**argv;
	char	**path;
	char	**env;
}	t_input;

//input handling
int		handle_input(int argc, char **argv);
t_input	new_input(char **argv, char **env);

//error handling
void	ft_exit(char *str);
void	ft_exit_close(char *str, t_fd fd, char **path);

//utils
void	split_free(char **str);
char	*read_file(int fd);
char	**get_path(char **env);
int		outfile(char **argv, int argc);

//pipex
int		run(t_fd fd, t_input input, int i);

#endif
