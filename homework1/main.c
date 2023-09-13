#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int getNum(void)
{
	int number = 0;
	char symbol = 0;

	while (true)
	{
		int input = scanf_s("%d%c", &number, &symbol);
		if (input == 2 && symbol == '\n' && number > 0)
		{
			break;
		}
		else
		{
			printf("\nInvalid input format\nTry again: ");
		}
		while ((symbol = getchar()) != '\n' && symbol != EOF);
	}
	return number;
}

int main()
{
	int limit = 0;
	printf("Enter the limit: ");
	limit = getNum();

	printf("\nPrime numbers not exceeding a given number: ");
	for (int number = 2; number < limit + 1; number++)
	{
		bool has_divisors = false;
		for (int divider = 2; divider < sqrt(number) + 1; divider++) {
			if (number % divider == 0) {
				has_divisors = true;
				break;
			}
		}
		if (!has_divisors) {
			printf("%d ", number);
		}
	}
	printf("\n");
}
