/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:47:26 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/10 11:27:36 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_exit_close(char *str, t_fd fd, char **path)
{
	perror(str);
	close(fd.infile);
	close(fd.outfile);
	split_free(path);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str)
{
	unlink("here_doc");
	perror(str);
	exit(EXIT_FAILURE);
}
