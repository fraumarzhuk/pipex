/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:58:31 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/04 15:47:16 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc != 5)
		return (printf("Too few arguments!"));
	f1 = open(argv[1], O_RDONLY, 0644);
	f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0 || read(f1, 0, 0) < 0)
	{
		perror("Error opening a file");
		exit(EXIT_FAILURE);
	}
	pipex(f1, f2, argv, envp);
	return (0);
}
