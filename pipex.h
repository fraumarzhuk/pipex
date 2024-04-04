/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:46:49 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/04 15:46:52 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h> 
# include <string.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"

char	*get_paths(char *cmd, char **envp);
void	exec_fun(char *argv, char **envp);
void	baby1_process(int f1, char **argv, int *end, char **envp);
void	baby2_process(int f2, char **argv, int end[], char **envp);
void	pipex(int f1, int f2, char **argv, char **envp);

#endif