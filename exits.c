#include "shell.h"

/**
 **_strncpy - copies a string
 *@dst: the destination string to be copied to
 *@srcc: the source string
 *@nn: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dst, char *srcc, int nn)
{
	int i, j;
	char *s = dst;

	i = 0;
	while (srcc[i] != '\0' && i < nn - 1)
	{
		dst[i] = srcc[i];
		i++;
	}
	if (i < nn)
	{
		j = i;
		while (j < nn)
		{
			dst[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dst: the first string
 *@srcc: the second string
 *@nn: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dst, char *srcc, int nn)
{
	int i, j;
	char *s = dst;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (srcc[j] != '\0' && j < nn)
	{
		dst[i] = srcc[j];
		i++;
		j++;
	}
	if (j < nn)
		dst[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@ss: the string to be parsed
 *@cc: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *ss, char cc)
{
	do {
		if (*ss == cc)
			return (ss);
	} while (*ss++ != '\0');

	return (NULL);
}
