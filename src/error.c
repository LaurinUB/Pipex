/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:50:04 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/02 10:29:26 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	file_error(void)
{
	ft_putendl_fd("first argument shoulde be a file", 2);
	exit(EXIT_FAILURE);
}