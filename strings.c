#include "monty.h"
/**
 * tokenize - turns the buffer into an array of strings
 * @buff: line buffer
 * @command: Array of strings to store tokens in
 */

void tokenize(char *buff, char **command)
{
	char *token, *str = buff;
	int i = 0;

	for (; i < 2; str = NULL, i++)
	{
		token = strtok(str, " \t\n");
		if (!token || token[0] == '#')
			return;
		command[i] = token;
	}
}

/**
 * is_digit - checks if a string consists of digits only
 * @str: string to check
 * Return: 1 if it's all digits, 0 otherwise
 */

int is_digit(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * reset_command - resets command values to NULL
 * @command: command
 */
void reset_command(char **command)
{
	int i;

	for (i = 0; i < 2; i++)
		command[i] = NULL;
}
