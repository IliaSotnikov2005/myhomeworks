#include <stdio.h>
#include <stdbool.h>

int getNum(void)
{
    int number = 0;
    char symbol = 0;

    while (true)
    {
        int input = scanf_s("%d%c", &number, &symbol);
        if (input == 2 && symbol == '\n')
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
    int number1 = 0;
    printf("Enter the first number: ");
    number1 = getNum();

    int number2 = 0;
    printf("\nEnter the second number: ");
    number2 = getNum();

    printf("\nInitial numbers: %d, %d\n", number1, number2);
    number1 += number2;
    number2 = number1 - number2;
    number1 = number1 - number2;
    printf("The resulting numbers: %d, %d\n", number1, number2);
}
