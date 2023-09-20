#include "string.h"
#include <stdlib.h>

/**
 *_strlen - a function that count the length of a string
 * @str: the parameter
 *
 * Return: the length
 */

int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcpy - a function that copies a string from src to dest
 * @dest: first parameter
 * @src: second parameter
 *
 * Return: return the dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - a function that concatonate two strings
 * @dest: the first parameter
 * @src: the second parameter
 *
 * Return: the dest
 */

char *_strcat(char *dest, const char *src)
{
	int len = _strlen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - a function that compare between two strings
 * @str1: the first parameter
 * @str2: second parameter
 *
 * Return: retturn the result of the first string minus the second
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

/**
 * _strdup - a function that duplicates a string
 * @str: the parameter
 *
 * Return: the duplicated string
 */


char *_strdup(const char *str)
{
	int len;
	char *dup_str;

	len = _strlen(str);
	dup_str = malloc((len + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	_strcpy(dup_str, str);
	return (dup_str);
}
