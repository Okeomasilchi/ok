#include "shell.h"

/**
 * st - Breaks a string into a sequence of zero or more nonempty tokens
 * @str: The string to be parsed 
 * @del: Set of bytes that delimit the tokens in the parsed string
 *
 * Return: Pointer to the next token,
 *		or NULL if there are no more tokens.
*/
char *s_tok(char *str, const char *del)
{
	char *tok_st = NULL, *tok_ed = NULL;
	static char *saved_str = NULL;

	if (str != NULL)
		saved_str = str;

	if (saved_str == NULL || *saved_str == '\0')
		return (NULL);

	tok_st = saved_str;

	while (*tok_st != '\0' && strchr(del, *tok_st) != NULL)
		tok_st++;

	tok_ed = tok_st;

	while (*tok_ed != '\0' && strchr(del, *tok_ed) == NULL)
		tok_ed++;

	if (*tok_ed != '\0')
	{
		*tok_ed = '\0';
		saved_str = tok_ed + 1;
	}
	else
	{
		saved_str = NULL;
	}

	return (tok_st);	
}

/**
 * prs - parses input command to tokens
 * @oki: struct of type okeoma
 * @coms: string to the parsed
 *
 * Return: void
*/
void prs(okeoma *oki, char *coms)
{
	char *com_cpy = NULL, *dl = " \t\n\r";
	size_t count = 0, cnt = 0;

	if (oki->cmd)
	{
		com_cpy = strdup(coms);
		oki->tok = strtok(coms, dl);
		while (oki->tok)
		{
			cnt++;
			oki->tok = strtok(NULL, dl);
		}
		cnt++;
		oki->av = malloc(sizeof(char *) * (cnt + 1));
		oki->tok = strtok(com_cpy, dl);
		while (oki->tok)
		{
			oki->av[count] = malloc(sizeof(char) * (_strlen(oki->tok) + 1));
			strcpy(oki->av[count], oki->tok);
			oki->tok = strtok(NULL, dl);
			count++;
		}
		oki->av[count] = NULL;
		free(com_cpy);
		com_cpy = NULL;
		count = 0, cnt = 0;
	}
}

/**
 * prs_2 - parses input command to tokens
 * @oki: struct of type okeoma
 *
 * Return: void
*/
void prs_2(okeoma *oki)
{
	char *com_cpy = NULL, *dl = ";\t\n";
	size_t count = 0, cnt = 0;

	if (oki->cmd)
	{
		com_cpy = strdup(oki->tok2);
		oki->tok = strtok(oki->tok2, dl);
		while (oki->tok)
		{
			cnt++;
			oki->tok = strtok(NULL, dl);
		}
		cnt++;
		oki->command = malloc(sizeof(char *) * (cnt + 1));
		oki->tok = strtok(com_cpy, dl);
		while (oki->tok)
		{
			oki->command[count] = malloc(sizeof(char) * (_strlen(oki->tok) + 1));
			strcpy(oki->command[count], oki->tok);
			oki->tok = strtok(NULL, dl);
			count++;
		}
		oki->command[count] = NULL;
		free(com_cpy);
		com_cpy = NULL;
		count = 0, cnt = 0;
	}
}
