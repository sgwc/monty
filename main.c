#include "monty.h"

/**
 * check_is_number - Checks if the string is a number
 *
 * @str: String to check
 * @line_number: Line number of the opcode
 * Return: 1 if it is a number, 0 if it is not
 */
void check_is_number(char *str, unsigned int line_number)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		/** positive and negative numbers */
		if (str[i] < '0' || str[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * parse_method - Parses the opcode and calls the corresponding function
 *
 * @content: Pointer to the line to parse
 * @line_number: Line number of the opcode
 * Return: void
 */
void parse_method(char *content, unsigned int line_number)
{
	char *args;
	void (*method_ptr)(stack_t **, unsigned int);
	char *method = strtok(content, " $\n");

	if (!method || method[0] == ' ')
		return;
	args = strtok(NULL, " $\n");
	if (args && (strcmp(method, "push") == 0))
	{
		check_is_number(args, line_number);
		global_stack = strdup(args);
	}

	method_ptr = get_method(method);
	if (!method_ptr)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, method);
		exit(EXIT_FAILURE);
	}
	method_ptr(&global_stack_head, line_number);
}
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(
	int argc __attribute__((unused)),
	char *argv[])
{
	int line_number;
	char *method_file, *content;
	FILE *fd;
	size_t len;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	method_file = argv[1];
	fd = fopen(method_file, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", method_file);
		exit(EXIT_FAILURE);
	}

	line_number = 0;
	content = NULL;
	while (getline(&content, &len, fd) != EOF)
	{
		line_number++;
		parse_method(content, line_number);
	}
	return (0);
}
