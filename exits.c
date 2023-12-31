#include "shell.h"

/**
 * *my_strncpy - to take copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * *@n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *my_strncpy(char *dest, char *src, int n)
{
	int h, k;
	char *s = dest;

	h = 0;
	while (src[h] != '\0' && h < n - 1)
	{
		dest[h] = src[h];
		h++;
	}
	if (h < n)
	{
		k = h;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 * *my_strncat - to concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *my_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * *my_strchr - to locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: (s) a pointer to the memory area s
 */
char *my_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
