/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:58:59 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/03 09:08:08 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

//input handling
int		handle_input(int argc, char **argv);

//error functions
void	file_error(void);

//utils
void	split_free(char **str);
char	**get_path(char **env);

//pipex
void	run(int fd, char **argv, int argc, char **path);

#endif
