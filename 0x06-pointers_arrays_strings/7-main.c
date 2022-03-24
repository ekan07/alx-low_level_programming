#include "main.h"
#include <stdio.h>

/**
 * main - check the code for
 *
 * Compile with gcc -Wall -pedantic -Werror -Wextra -std=gnu89
 * 7-main.c 7-leet.c -o 7-1337
 *
 * Return: Always 0.
 */
int main(void)
{
	char s[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\n";
	char *p;

	p = leet(s);
	printf("%s", p);
	printf("%s", s);
	return (0);
}
