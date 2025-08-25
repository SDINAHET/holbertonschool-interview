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
 * print_error - prints "Error" and exits with code 98
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
 * multiply_numbers - core multiplication of two numeric strings
 * @num1: first number string (digits only)
 * @num2: second number string (digits only)
 * @result: buffer to hold digits of the product
 * @len1: length of num1
 * @len2: length of num2
 *
 * Description: Fills @result with the product digits (base 10),
 * most significant digit possibly at an initial zero index.
 */
static void multiply_numbers(char *num1, char *num2, int *result,
			     int len1, int len2)
{
	int i, j, carry, n1, n2;

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
}

/**
 * print_result - prints the product digits stored in @result
 * @result: array of digits
 * @len_r: length of result array
 *
 * Description: Skips leading zeros; prints single '0' if product is zero.
 */
static void print_result(int *result, int len_r)
{
	int start = 0;

	while (start < len_r && result[start] == 0)
		start++;

	if (start == len_r)
	{
		_putchar('0');
	}
	else
	{
		for (; start < len_r; start++)
			_putchar(result[start] + '0');
	}
	_putchar('\n');
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
	int len1, len2, len_r, *result;

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

	multiply_numbers(num1, num2, result, len1, len2);
	print_result(result, len_r);

	free(result);
	return (0);
}
