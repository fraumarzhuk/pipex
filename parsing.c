/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:55:59 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/06 15:33:05 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *cmd)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			j = i + 1;
			while (cmd[j] != cmd[i] && cmd[j])
				j++;
			if (cmd[j])
			{
				cmd[i] = 26;
				cmd[j] = 26;
				i = j;
			}
		}
		else if (cmd[i] == ' ')
			cmd[i] = 26;
		i++;
	}
	res = ft_split(cmd, 26);
	return (res);
}

char	*check_direct_command(char *cmd)
{
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0)
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		else
			pipex_error("Command not executable or not found");
	}
	return (NULL);
}
