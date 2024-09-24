#include "monty.h"
#include <stdio.h>
/**
 * main - monty entry point
 * @argc: argument count
 * @argv: arguments values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char const *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = read_file(argv[1]);
	return (0);
}
