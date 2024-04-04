/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:58:31 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/04 13:29:05 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_paths(char **envp)
{
    char **paths;
    while (ft_strncmp("PATH", *envp, 4))
        envp++;
    paths = ft_split(*envp + 5, ':');
    if (!paths)
    {
        free_split(paths);
        ft_printf("Malloc failed");
        exit(1);
    }
    return (*paths);
}

void exec_fun(char **cmd1, char **cmd2, char **envp)
{
    char *path = get_paths(envp);
    if (!path)
    {
        free(cmd1);
        free(cmd2);
        perror("Path not found: ");
    }
    else if ((execve(path, cmd1, envp) == - 1) || execve(path, cmd2, envp) == - 1)
        perror("Execution error: ");
}

void baby1_process(int f1, char **cmd1, char **cmd2, int *end, char **envp)
{
    if (dup2(f1, 0) < 0)
       return (perror("Dup2 error: "));
    close(STDIN_FILENO); 
    if (dup2(end[1], 1) < 0)
        return (perror("Dup2 error: "));
    close(end[0]);
    exec_fun(cmd1, cmd2, envp);
    close(f1);
}

void baby2_process(int f2, char **cmd1, char **cmd2, int end[], char **envp)
{
    waitpid(-1, NULL, 0);
    if (dup2(end[0], 0) < 0)
        return (perror("Dup2 error: "));
    close(STDIN_FILENO);
    if (dup2(f2, 1) < 0)
        return (perror("Dup2 error: "));
    close(end[0]);
    exec_fun(cmd1, cmd2, envp);
}

// Enviroment


void pipex(int f1, int f2, char **cmd1, char **cmd2, char **envp)
{
    int end[2];
    pid_t baby1;
    pid_t baby2;

    pipe(end);
    baby1 = fork();
    if (baby1 < 0)
        return (perror("Fork: "));
    if (baby1 == 0)
        baby1_process(f1, cmd1, cmd2, end, envp);
    baby2 = fork();
    if (baby2 < 0)
        return (perror("Fork: "));
    if (baby2 == 0)
        baby2_process(f2, cmd1, cmd2, end, envp);
    close(end[0]);
    close(end[1]);
    waitpid(baby1, NULL, 0);
    waitpid(baby2, NULL, 0);
}

int main(int argc, char **argv, char **envp)
{
    if (argc < 2)
        printf("error\n");
    int f1 = open(argv[1], O_RDONLY| O_CREAT | O_TRUNC, 0644);
    int f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0 || read(f1, 0, 0) < 0 || read(f2, 0, 0) < 0)
    {
        (perror("Error opening a file"));
        exit(-1);
    }
    char **cmd1 = ft_split(argv[2], ' ');
    char **cmd2 = ft_split(argv[3], ' ');
    pipex(f1, f2, cmd1, cmd2, envp);
    
    return (0);
}