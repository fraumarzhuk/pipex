/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:58:31 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/06 16:04:53 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc != 5)
		return (printf("Incorrect amount of arguments!"));
	f1 = open(argv[1], O_RDONLY, 0644);
	f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0 || read(f1, 0, 0) < 0)
		pipex_error("Error opening a file.");
	pipex(f1, f2, argv, envp);
	close(f1);
	close(f2);
	return (0);
}
