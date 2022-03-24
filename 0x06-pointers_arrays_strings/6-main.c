#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Compile with gcc -Wall -pedantic -Werror -Wextra -std=gnu89
 * 6-main.c 6-cap_string.c -o 6-cap
 *
 * Return: Always 0.
 */
int main(void)
{
	char str[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\nhello world! hello-world 0123456hello world\thello world.hello world\n";
	char *ptr;

	ptr = cap_string(str);
	printf("%s", ptr);
	printf("%s", str);
	return (0);
}
