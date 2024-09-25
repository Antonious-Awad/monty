#include "monty.h"

sv STACK = {NULL, NULL, NULL, NULL};
/**
 * main - monty entry point
 * @argc: argument count
 * @argv: arguments values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	FILE *file;
	size_t size;
	int line;
	char *command[2] = {NULL, NULL};
	char *buff;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = read_file(argv[1]);
	STACK.stream = file;

	while (getline(&buff, &size, file) != -1)
	{
		STACK.buff = buff;
		line++;
		command[0] = NULL;
		command[1] = NULL;
		tokenize(buff, command);
		STACK.command = command;
		if (command[0])
			run_command(line);
	}
	free(buff);
	fclose(file);
	free_dbl_list(STACK.top);
	return (0);
}
