#include "main.h"

int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t num_read;
	char *lineptr_cpy = NULL;
	const char *delim = " \n";
	char *token;
	int num_token = 0;
	int i, count;

	(void)argc;

	while (1)
	{
		printf("$ ");
		num_read = getline(&lineptr, &n, stdin);

		if (num_read == -1)
		{
			printf("Exiting Shell....\n");
			return (-1);
		}

		lineptr_cpy = malloc(sizeof(char) * num_read);
		if (lineptr_cpy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		strcpy(lineptr_cpy, lineptr);

		/* Tokenizing lineptr */
		token = strtok(lineptr, delim);

		/* Deterning the number of tokens generated from lineptr */
		if (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim);
		}
		num_token++;

		argv = malloc(sizeof(char *) * num_token);

		token = strtok(lineptr_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			strtok(NULL, delim);
		}
		argv[i] = NULL;

		for (count = 0; count < num_token; count++)
		{
			printf("%s\n", argv[count]);
		}

		free(lineptr);
		free(lineptr_cpy);
		free(argv);
	}
	return (0);
}
