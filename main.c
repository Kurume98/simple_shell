#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @ac: The argument count.
 * @argv: The array of argument strings.
 *
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
    char *line = NULL;
    char **command = NULL;
    int status;

    (void) ac; // Unused parameter

    while (1)
    {
        // Read input line
        line = read_line();

        // Tokenize the input line
        command = tokenizer(line);

        // Execute the command
        status = _execute(command, argv);
    }

    return 0;
}
