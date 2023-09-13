#include <stdio.h>
#include <stdbool.h>

int getNum(void)
{
	int number = 0;
	char sybol = 0;

	while (true)
	{
		int input = scanf_s("%d%c", &number, &sybol);
		if (input == 2 && sybol == '\n')
		{
			break;
		}
		else
		{
			printf("\nInvalid input format\nTry again: ");
		}
		while ((sybol = getchar()) != '\n' && sybol != EOF);
	}
	return number;
}

int main()
{
	int number1 = 0;
	printf("Enter the dividend\na = ");
	number1 = getNum();

	int number2 = 0;
	printf("\nEnter the divisor\nb = ");
	number2 = getNum();

	if (number2 == 0)
	{
		printf("\nError: Division by zero\n");
		return 0;
	}

	bool is_negative = (number1 < 0) != (number2 < 0);

	if (number1 < 0)
	{
		number1 = -number1;
	}
	if (number2 < 0)
	{
		number2 = -number2;
	}

	int incomplete_quotient = 0;
	while (number1 >= number2)
	{
		number1 -= number2;
		incomplete_quotient++;
	}
	if (is_negative)
	{
		incomplete_quotient = -incomplete_quotient;
	}

	printf("\nResult of an incomplete quotient: %d\n", incomplete_quotient);
}
