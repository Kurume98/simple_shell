/*
 * Simple Shell in C
 * Author: OpenAI (modified for Betty style)
 *
 * Description:
 * This program implements a basic shell that displays a prompt, waits for the
 * user to enter a command, executes the command using execve, displays the
 * output, and then displays the prompt again. It continues to run until the
 * user enters 'exit' or 'quit' or triggers the end-of-file condition (Ctrl+D).
 *
 * Command lines are simple: no semicolons, no pipes, no redirections, or any
 * other advanced features. Command lines are made only of one word, and no
 * arguments will be passed to programs. If an executable cannot be found,
 * print an error message and display the prompt again. Handle errors
 * gracefully. You have to handle the "end of file" condition (Ctrl+D).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * shell_loop - Main loop of the shell
 */
void shell_loop(void)
{
    char input[MAX_INPUT_SIZE];

    while (1)
    {
        /* Display the prompt */
        printf("$ ");

        /* Read user input */
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
        {
            if (feof(stdin)) {
                /* End of file condition (Ctrl+D) */
                printf("Exiting shell.\n");
                exit(EXIT_SUCCESS);
            } else {
                perror("Error reading input");
                continue;
            }
        }

        /* Remove newline character */
        input[strcspn(input, "\n")] = '\0';

        /* Exit the shell if the user enters 'exit' or 'quit' */
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0)
        {
            break;
        }

        /* Check for advanced features in the command line */
        if (strpbrk(input, ";|><&"))
        {
            printf("Error: Unsupported features in the command line.\n");
            continue;
        }

        /* Check if the command line contains spaces (more than one word) */
        if (strchr(input, ' ') != NULL)
        {
            printf("Error: Command lines should contain only one word.\n");
            continue;
        }

        /* Fork a child process */
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("Fork failed");
            continue;
        }
        else if (pid == 0)
        {
            /* Child process */

            /* Execute the command using execve */
            if (execlp(input, input, (char *)NULL) == -1)
            {
                perror("Exec failed");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process */

            /* Wait for the child to complete */
            int status;
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("Waitpid failed");
                continue;
            }

            /* Check if an executable cannot be found */
            if (WIFEXITED(status))
            {
                if (WEXITSTATUS(status) == 127)
                {
                    printf("Error: Executable not found.\n");
                }
                else if (WEXITSTATUS(status) != 0)
                {
                    printf("Error: Command exited with non-zero status.\n");
                }
            }
            else if (WIFSIGNALED(status))
            {
                printf("Error: Command terminated by signal %d.\n", WTERMSIG(status));
            }
        }
    }
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
    printf("Simple Shell in C. Type 'exit' or 'quit' to exit.\n");

    while (1)
    {
        shell_loop();
    }

    return 0;
}

