#include <stdlib.h>
#include <string.h>

#include "substring.h"

/**
 * build_word_info - Build arrays of unique words and their counts
 * @words: array of words (may contain duplicates)
 * @nb_words: number of words in @words
 * @uniq_words: output: array of unique words
 * @uniq_count: output: array of counts per unique word
 * @uniq_nb: output: number of unique words
 *
 * Return: 0 on success, -1 on failure
 */
static int build_word_info(char const **words, int nb_words,
			   char const ***uniq_words, int **uniq_count,
			   int *uniq_nb)
{
	int i, j, found;

	*uniq_words = malloc(sizeof(char *) * nb_words);
	if (*uniq_words == NULL)
		return (-1);

	*uniq_count = malloc(sizeof(int) * nb_words);
	if (*uniq_count == NULL)
	{
		free(*uniq_words);
		return (-1);
	}

	*uniq_nb = 0;
	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < *uniq_nb; j++)
		{
			if (strcmp(words[i], (*uniq_words)[j]) == 0)
			{
				(*uniq_count)[j] += 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			(*uniq_words)[*uniq_nb] = words[i];
			(*uniq_count)[*uniq_nb] = 1;
			*uniq_nb += 1;
		}
	}

	return (0);
}

/**
 * find_word_index - Find index of a word inside the unique words array
 * @s: pointer to the substring in the main string
 * @uniq_words: array of unique words
 * @uniq_nb: number of unique words
 * @word_len: length of one word
 *
 * Return: index in uniq_words, or -1 if not found
 */
static int find_word_index(char const *s, char const **uniq_words,
				int uniq_nb, int word_len)
{
	int i;

	for (i = 0; i < uniq_nb; i++)
	{
		if (strncmp(s, uniq_words[i], word_len) == 0)
			return (i);
	}
	return (-1);
}

/**
 * find_substring - Find all starting indices of substrings in s that are
 *                  concatenations of all given words exactly once.
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of words in @words
 * @n: address at which to store number of found indices
 *
 * Return: malloc'ed array of indices, or NULL if none (or on error).
 */
int *find_substring(char const *s, char const **words,
			int nb_words, int *n)
{
	int *indices = NULL;
	int len_s, word_len, total_len;
	int i, j, k, idx, found;
	char const **uniq_words = NULL;
	int *uniq_count = NULL, *cur_count = NULL;
	int uniq_nb = 0;

	if (n == NULL)
		return (NULL);
	*n = 0;

	if (s == NULL || words == NULL || nb_words <= 0)
		return (NULL);

	len_s = (int)strlen(s);
	word_len = (int)strlen(words[0]);
	if (word_len == 0)
		return (NULL);

	total_len = word_len * nb_words;
	if (total_len > len_s)
		return (NULL);

	if (build_word_info(words, nb_words, &uniq_words,
				&uniq_count, &uniq_nb) == -1)
		return (NULL);

	cur_count = malloc(sizeof(int) * uniq_nb);
	if (cur_count == NULL)
	{
		free(uniq_words);
		free(uniq_count);
		return (NULL);
	}

	indices = malloc(sizeof(int) * len_s);
	if (indices == NULL)
	{
		free(uniq_words);
		free(uniq_count);
		free(cur_count);
		return (NULL);
	}

	found = 0;
	for (i = 0; i <= len_s - total_len; i++)
	{
		for (k = 0; k < uniq_nb; k++)
			cur_count[k] = 0;

		for (j = 0; j < nb_words; j++)
		{
			idx = find_word_index(s + i + j * word_len,
						  uniq_words, uniq_nb, word_len);
			if (idx == -1)
				break;

			cur_count[idx] += 1;
			if (cur_count[idx] > uniq_count[idx])
				break;
		}

		if (j == nb_words)
		{
			indices[found] = i;
			found++;
		}
	}

	free(uniq_words);
	free(uniq_count);
	free(cur_count);

	if (found == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = found;
	return (indices);
}
