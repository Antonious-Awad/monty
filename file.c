#include "monty.h"
/**
 * read_file - reads file content
 * @name: name of the file
 * Return: file pointer to the stream data
 */

FILE *read_file(char *name)
{
	FILE *data;

	data = fopen(name, "r");

	if (!data)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <file>");
		exit(EXIT_FAILURE);
	}

	return (data);
}
/**
 * tokenize - turns the buffer into an array of strings
 * @buff: line buffer
 * @command: Array of strings to store tokens in
 */

void tokenize(char *buff, char **command)
{
	char *token, *data = buff;
	int i = 0;

	for (; i < 2; i++)
	{
		token = strtok(data, " \n\t");
		if (!token || token[0] == '#')
			return;
		command[i] = token;
	}
}
