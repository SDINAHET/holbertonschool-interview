#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long integer is a palindrome
 * @n: The number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n, digit;

	while (n != 0)
	{
		digit = n % 10;
		reversed = reversed * 10 + digit;
		n /= 10;
	}

	return (original == reversed);
}
