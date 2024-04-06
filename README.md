<h2>Project Overview</h2>
The Pipex project involves creating a command-line program that mimics the behavior of the shell command pipeline (|). It takes two commands and redirects the output of the first command as the input of the second command, emulating the behavior of the shell's pipe operator.

<h2>Key Features</h2>
The Pipex project includes the following key features:

<i>Command Execution:</i> Pipex allows users to execute two commands, just like in a shell pipeline. It handles the execution of the commands and sets up the appropriate file descriptors for input/output redirection.

Input/Output Redirection: Pipex supports input and output redirection using file descriptors. It allows users to specify input and output files for the commands, redirecting their standard input/output accordingly.

File Creation and Permissions: The program handles the creation of output files and sets the appropriate permissions for the newly created files.

Error Handling: Pipex provides error handling mechanisms for various scenarios, such as invalid commands, file-related errors, and failures during command execution.

<h2>Getting Started</h2>
To get started with Pipex, follow these steps:

Clone the repository to your local machine. Compile the source code using the provided makefile. Run the resulting executable, providing the appropriate command-line arguments for input and output files, as well as the two commands to execute. Pipex will execute the commands and redirect the input/output according to the specified file descriptors.
