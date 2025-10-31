#include "holberton.h"

/**
 * wildcmp - compares two strings, considering * as a wildcard
 * @s1: string to compare
 * @s2: pattern string that can contain *
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* both at end -> match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* if pattern has *, it can match empty or more chars */
	if (*s2 == '*')
	{
		/* skip consecutive * to avoid infinite recursion */
		while (*s2 == '*')
			s2++;

		/* if * was at the very end, it matches everything */
		if (*s2 == '\0')
			return (1);

		/*
		 * try to match the rest of s2 somewhere in s1
		 * move s1 forward until rest matches
		 */
		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2))
				return (1);
			s1++;
		}
		return (0);
	}

	/* chars match (and not at end) → continue */
	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));

	/* otherwise, no match */
	return (0);
}
