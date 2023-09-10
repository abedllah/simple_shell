/**
 * print_numbers - Print numbers from 1 to n.
 * @n: The upper limit for numbers to print.
 */
void print_numbers(int n)
{
	int i;

	for (i = 1; i <= n; i++)
	{
		if (i < n)
			printf("%d, ", i);
		else
			printf("%d\n", i);
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	int limit = 10;

	printf("Printing numbers from 1 to %d:\n", limit);
	print_numbers(limit);

	return (0);
}
