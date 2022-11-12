#include "shell.h"
#include <stdlib.h>
#include <stddef.h>

/**
 *
 */

int _strcmp(char *s1, char *s2)
{
	int dif = 0, i = 0;

	while (!dif && s1[i] && s2[i])
	{
		dif = s1[i] - s2[i];
		i++;
	}

	if (!*s1)
		dif = -*s2;
	else if (!*s2)
		dif = *s1;

	return (dif);
}

/**
 *
 *
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	int dif = 0;
	size_t i = 0;

	while (!dif && s1[i] && s2[i] && i < n)
	{
		dif = s1[i] - s2[i];
		i++;
	}

	if (!*s1)
		dif = -*s2;
	if (!*s2)
		dif = *s1;
	return (dif);
}

/**
 *
 */

char *_strstr(char *hay, char *ndl)
{

	size_t i = 0, j = 0, st = 0;
	char *p;

	if (!*ndl)
		return (hay);
	while (hay[i])
	{
		if (st && hay[i] == ndl[j])
		{
			j++;
		}
		else if (!st && hay[i] == ndl[j])
		{
			p = hay + i;
			st = 1;
			j++;
		}
		else if (st && hay[i] != ndl[j] && ndl[j])
		{
			st = 0;
			j = 0;
		}
		i++;
		if (!ndl[j] && j > 0)
			return (p);
	}
	return (NULL);
}

/**
 *
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, st = 0, j = 0;

	while (src[i])
	{
		if (st)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		else if (dest[j])
		{
			j++;
		}
		else if (!dest[j])
		{
			st = 1;
		}
	}
	dest[j] = '\0';
	return (dest);
}

/**
 *
 */

size_t _strlen(char *s)
{
	if (!*s)
		return (0);
	else
		return (1 + _strlen(s + 1));	
}


