/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:58:31 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/04/04 14:56:26 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_paths(char *cmd, char **envp)
{
    int i;
    char **paths;
    char *temp_path;
    char *cmd_path;
    
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
            return(cmd_path);
        free(cmd_path);
        i++;
    }
    i = 0;
    free_split(paths);
    return (0);
}

void exec_fun(char *argv, char **envp)
{
    char **cmds = ft_split(argv, ' ');
    char *path = get_paths(cmds[0], envp);
    if (!path)
    {
        perror("Path not found: ");
    }
    else if ((execve(path, cmds, envp) == -1))
    {
        perror("Execution error: ");
    }
}

void baby1_process(int f1, char **argv, int *end, char **envp)
{
    if (dup2(end[1], STDOUT_FILENO) < 0)
       return (perror("Dup2 error child1.1: "));
    // close(STDOUT_FILENO); 
    if (dup2(f1, STDERR_FILENO) < 0)
        return (perror("Dup2 error child1.2: "));
    close(end[0]);
    exec_fun(argv[2], envp);
    // close(f1);
}

void baby2_process(int f2, char **argv, int end[], char **envp)
{
    if (dup2(end[0], STDIN_FILENO) < 0)
        return (perror("Dup2 error child2.1: "));
    // close(STDIN_FILENO);
    if (dup2(f2, STDOUT_FILENO) < 0)
        return (perror("Dup2 error child2.2: "));
    close(end[0]);
    exec_fun(argv[3], envp);
}

void pipex(int f1, int f2, char **argv, char **envp)
{
    int end[2];
    pid_t baby1;
    pid_t baby2;

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
    printf("check\n");
}


int main(int argc, char **argv, char **envp)
{
    if (argc != 5)
        printf("Too few arguments!");
    int f1 = open(argv[1], O_RDONLY, 0644);
    int f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0 || read(f1, 0, 0) < 0)
    {
        (perror("Error opening a file"));
        exit(-1);
    }
    pipex(f1, f2, argv, envp); 
    return (0);
}