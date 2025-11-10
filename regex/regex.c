#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a string.
 * Supports '.' (any single char) and '*' (zero or more of preceding char).
 *
 * @str:     The input string (may be empty but not NULL).
 * @pattern: The regex pattern (may be empty but not NULL).
 *
 * Return: 1 if pattern matches the whole string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);

	/* If pattern is empty, match only if string is empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Handle X* (zero or more of preceding token) */
	if (pattern[1] == '*')
	{
		/* Try zero occurrence of the token first */
		if (regex_match(str, pattern + 2))
			return (1);

		/* Then try consuming characters while first token matches */
		while (*str && (*pattern == '.' || *pattern == *str))
		{
			str++;
			if (regex_match(str, pattern + 2))
				return (1);
		}
		return (0);
	}

	/* Handle single-character match (regular char or '.') */
	if (*str && (*pattern == '.' || *pattern == *str))
		return (regex_match(str + 1, pattern + 1));

	/* No match */
	return (0);
}
