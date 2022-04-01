#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int amount, j, result;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	amount = atoi(argv[1]);
	result = 0;

	if (amount < 0)
	{
		printf("0\n");
		return (0);
	}

	for (j = 0; j < 5 && amount >= 0; j++)
	{
		while (amount >= coins[j])
		{
			result++;
			amount -= coins[j];
		}
	}

	printf("%d\n", result);
	return (0);
}
