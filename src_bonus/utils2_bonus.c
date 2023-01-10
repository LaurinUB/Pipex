/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:58:28 by luntiet-          #+#    #+#             */
/*   Updated: 2023/01/10 14:04:24 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	**split_on_whitespace(char *argv)
{
	if (ft_strchr(argv, '\t'))
		return (ft_split(argv, '\t'));
	else
		return (ft_split(argv, ' '));
}

t_input	new_input(char **argv, char **env)
{
	t_input	input;

	input.path = get_path(env);
	input.argv = argv;
	input.env = env;
	return (input);
}

char	*awk_handle(char *cmd)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strtrim(cmd, "awk ");
	new[0] = ' ';
	new[ft_strlen(new) - 1] = ' ';
	while (new[i])
	{
		if (new[i] == '\\')
			new[i] = ' ';
		i++;
	}
	new = ft_strjoin("awk ", new);
	return (new);
}

char	*change(char *cmd)
{
	int	i;

	i = 0;
	if (ft_strnstr(cmd, "awk", 3))
		cmd = awk_handle(cmd);
	else
	{
		while (cmd[i])
		{
			if (cmd[i] == '\'' || cmd[i] == '\"')
				cmd[i] = ' ';
			i++;
		}
	}
	return (cmd);
}
