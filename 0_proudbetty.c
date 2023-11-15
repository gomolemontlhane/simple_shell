#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on successful execution
 */

int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d is even\n", i);
		}
		else
		{
			printf("%d is odd\n", i);
		}
	}
	return (0);
}
