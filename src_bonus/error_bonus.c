/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:47:26 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/05 19:19:18 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_exit_close(char *str, t_fd fd, char **path)
{
	ft_putendl_fd(str, 2);
	close(fd.infile);
	close(fd.outfile);
	split_free(path);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
