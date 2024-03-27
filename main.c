/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:58:31 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/03/27 16:53:58 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child1_process(int f1, char *cmd1, int end[])
{
    close(end[0]);
    dup2(f1, 0); //switch file to input to input, donate data to 0 - stdin
    close(f1);
    dup2(end[1], 1);
    // add protection if dup2() < 0
    // dup2 close stdin, f1 becomes the new stdin
    // dup2(f1, STDIN_FILENO); // we want f1 to be execve() input
    // dup2(end[1], STDOUT_FILENO); // we want end[1] to be execve() stdout
    // close(end[0]) # --> always close the end of the pipe you don't use,
    //                     as long as the pipe is open, the other end will 
    //                     be waiting for some kind of input and will not
    //                     be able to finish its process
    // close(f1)
    // execve function for each possible path (see below)
    exit(EXIT_FAILURE);
    ft_printf("Child\n");
}

void child2_process(int f2, char *cmd2, int end[])
{
    close(end[1]);
    dup2(f2, 1);
    close(f2);
    dup2(end[1],1);
    // int status;
    // waitpid(-1, &status, 0);
    // dup2(f2, ...); // f2 is the stdout
    // dup2(end[0], ...); // end[0] is the stdin
    // close(end[1])
    // close(f2);
    // // execve function for each possible path (see below)
    // exit(EXIT_FAILURE);
    ft_printf("Parent/n");
}

// Enviroment

void pipex(int f1, int f2, char *cmd1, char *cmd2)
{
    int end[2];
    int status;
    pid_t child1;
    pid_t child2;

    pipe(end);
    child1 = fork();
    if (child1 < 0) //if parent returns negative --> error
        return (perror("Fork: "));
    if (child1 == 0) // child process returns 0 if it sucessfully runs
        child1_process(f1, cmd1, end);
    child2 = fork();
    if (child2 < 0)
        return (perror("Fork: "));
    if (child2 == 0)
        child2_process(f1, cmd2, end);
    close(end[0]);
    close(end[1]);
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
}

int main(int argc, char **argv, char **envp)
{
    int f1 = open(argv[1], O_RDONLY);
    int f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0 || read(f1, 0, 0) < 0 || read(f2, 0, 0) < 0)
    {
        (perror("Error opening a file"));
        exit(-1);
    }
    char **cmd1 = ft_split(argv[2], ' ');
    char **cmd2 = ft_split(argv[3], ' ');
    pipex(f1, f2, cmd1, cmd2);
    
    return (0);
}