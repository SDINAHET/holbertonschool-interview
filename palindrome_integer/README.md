palindrome_integer


alex@~/palindrome_integer$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
alex@~/palindrome_integer$ ./palindrome 1
1 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 11
11 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 112
112 is not a palindrome.
alex@~/palindrome_integer$ ./palindrome 121
121 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
alex@~/palindrome_integer$
