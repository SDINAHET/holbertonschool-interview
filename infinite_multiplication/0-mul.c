#include "mul.h"
#include <stdlib.h>

/**
 * _is_digit - checks if a string contains only digits
 * @s: input string
 * Return: 1 if only digits, 0 otherwise
 */
int _is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * print_error - prints Error and exits with code 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * main - multiply two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len_r, i, j, carry, n1, n2, *result, start = 0;

	if (argc != 3 || !_is_digit(argv[1]) || !_is_digit(argv[2]))
		print_error();

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len_r = len1 + len2;

	result = calloc(len_r, sizeof(int));
	if (!result)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	while (start < len_r && result[start] == 0)
		start++;

	if (start == len_r)
		_putchar('0');
	else
	{
		for (; start < len_r; start++)
			_putchar(result[start] + '0');
	}
	_putchar('\n');

	free(result);
	return (0);
}
