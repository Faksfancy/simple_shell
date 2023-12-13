#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @inff: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *inff)
{
	return (isatty(STDIN_FILENO) && inff->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @cc: the char to check
 * @delimm: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char cc, char *delimm)
{
	while (*delimm)
		if (*delimm++ == cc)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@cc: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int cc)
{
	if ((cc >= 'a' && cc <= 'z') || (cc >= 'A' && cc <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@ss: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *ss)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  ss[i] != '\0' && flag != 2; i++)
	{
		if (ss[i] == '-')
			sign *= -1;

		if (ss[i] >= '0' && ss[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (ss[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
