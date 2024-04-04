/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:27:59 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/04 15:45:49 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_paths(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*temp_path;
	char	*cmd_path;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	i = 0;
	free_split(paths);
	return (0);
}

void	exec_fun(char *argv, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(argv, ' ');
	if (!cmds)
	{
		printf("Malloc failed!\n");
		exit(EXIT_FAILURE);
	}
	path = get_paths(*cmds, envp);
	if (!path)
	{
		free_split(cmds);
		perror("Path not found: ");
		exit(EXIT_FAILURE);
	}
	if ((execve(path, cmds, envp) == -1))
	{
		perror("Execution error: ");
		free_split(cmds);
		exit(EXIT_FAILURE);
	}
	perror("Execution error: ");
	free_split(cmds);
	exit(EXIT_FAILURE);
}

void	baby1_process(int f1, char **argv, int *end, char **envp)
{
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return (perror("Dup2 error child1.1: "));
	if (dup2(f1, STDIN_FILENO) < 0)
		return (perror("Dup2 error child1.2: "));
	close(end[0]);
	close(end[1]);
	exec_fun(argv[2], envp);
	perror("Execution error: ");
	exit(EXIT_FAILURE);
}

void	baby2_process(int f2, char **argv, int end[], char **envp)
{
	if (dup2(end[0], STDIN_FILENO) < 0)
		return (perror("Dup2 error child2.1: "));
	if (dup2(f2, STDOUT_FILENO) < 0)
		return (perror("Dup2 error child2.2: "));
	close(end[0]);
	close(end[1]);
	exec_fun(argv[3], envp);
	perror("Execution error: ");
	exit(EXIT_FAILURE);
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		end[2];
	pid_t	baby1;
	pid_t	baby2;

	if (pipe(end) == -1)
		perror("Error piping:");
	baby1 = fork();
	if (baby1 < 0)
		return (perror("Forking1: "));
	if (baby1 == 0)
		baby1_process(f1, argv, end, envp);
	baby2 = fork();
	if (baby2 < 0)
		return (perror("Forking2: "));
	if (baby2 == 0)
		baby2_process(f2, argv, end, envp);
	close(end[0]);
	close(end[1]);
	waitpid(baby1, NULL, 0);
	waitpid(baby2, NULL, 0);
	close(f1);
	close(f2);
}
