#include "main.h"

/**
 * _puts_recursion - print a string follow by newline
 *
 * @s: string to print
 */
void _puts_recursion(char *s)
{
	int i;

	i = 0;
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	i++;
	_puts_recursion(s + i);
}
