#include "main.h"

/**
 * _pow_recursion - returns a value of a number
 * raise to power a number.
 *
 * @x: number
 * @y: number to be raise
 * Return: the value of the x raise to y
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)
	{
		return (1);
	}
	else if (y < 0)
	{
		return (-1);
	}

	return (x * _pow_recursion(x, y - 1));
}
