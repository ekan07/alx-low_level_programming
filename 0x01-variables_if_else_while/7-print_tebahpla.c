#include <stdio.h>

/**
  * main - Prints the alphabet at reverse order
  *
  * Return: Always (Success)
  */
int main(void)
{
	char reverse_alpha;

	for (reverse_alpha = 'z'; reverse_alpha >= 'a'; reverse_alpha--)
	{
		putchar(reverse_alpha);
	}

	putchar('\n');

	return (0);
}
