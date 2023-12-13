#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @st: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *st)
{
	int j = 0;
	unsigned long int resultt = 0;

	if (*st == '+')
		st++;  /* TODO: why does this make main return 255? */
	for (j = 0;  st[j] != '\0'; j++)
	{
		if (st[j] >= '0' && st[j] <= '9')
		{
			resultt *= 10;
			resultt += (st[j] - '0');
			if (resultt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (resultt);
}

/**
 * print_error - prints an error message
 * @inf: the parameter & return info struct
 * @estrr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *inf, char *estrr)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(estrr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, countt = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		countt++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			countt++;
		}
		current %= j;
	}
	__putchar('0' + current);
	countt++;

	return (countt);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long nn = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		nn = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[nn % base];
		nn /= base;
	} while (nn != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buff)
{
	int j;

	for (j = 0; buff[j] != '\0'; j++)
		if (buff[j] == '#' && (!j || buff[j - 1] == ' '))
		{
			buff[j] = '\0';
			break;
		}
}
