#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Compile with gcc -Wall -pedantic -Werror -Wextra -std=gnu89  2-main.c 
 * 2-strlen_recursion.c -o 2-strlen_recursion
 *
 * Return: Always 0.
 */
int main(void)
{
    int n;

    n = _strlen_recursion("Corbin Coleman");
    printf("%d\n", n);
    return (0);
}
