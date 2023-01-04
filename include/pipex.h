/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:58:59 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/04 14:01:06 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_fd
{
	int	infile;
	int	outfile;
}	t_fd;

//input handling
int		handle_input(int argc, char **argv);

//error functions
void	ft_exit(char *str);
void	file_error(void);

//utils
void	split_free(char **str);
char	*read_file(int fd);
char	**get_path(char **env);

//pipex
int		run(t_fd fd, char **argv, int i, char **path);

#endif
