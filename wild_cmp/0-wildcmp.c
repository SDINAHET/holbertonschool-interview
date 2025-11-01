#include "holberton.h"

/**
 * wildcmp - compares two strings, where s2 can contain the wildcard *
 * @s1: first string
 * @s2: second string (may contain *)
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* both ended */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* if we encounter a '*' in s2 */
	if (*s2 == '*')
	{
		/* if '*' is the last character, it matches anything */
		if (*(s2 + 1) == '\0')
			return (1);

		/* if s1 still has chars, try both recursive paths */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		/* or skip the '*' in s2 */
		return (wildcmp(s1, s2 + 1));
	}

	/* if current characters match, move both forward */
	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));

	/* otherwise, no match */
	return (0);
}
