#include "main.h"

int _strlen_recursion(char *s);
int check_palindrome(char *s, int len, int index);

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if it is a palindrome, 0 if not.
 */
int is_palindrome(char *s)
{
	int len;

	if (*s == '\0')
		return (1);

	len = _strlen_recursion(s);
	return (check_palindrome(s, len, 0));
}

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string to check.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - Recursively checks characters from start and end.
 * @s: The string to check.
 * @len: Total length of the string.
 * @index: Current index from the start.
 *
 * Return: 1 if match continues to the middle, 0 if mismatch.
 */
int check_palindrome(char *s, int len, int index)
{
	if (index >= len / 2)
		return (1);

	if (s[index] != s[len - 1 - index])
		return (0);

	return (check_palindrome(s, len, index + 1));
}
