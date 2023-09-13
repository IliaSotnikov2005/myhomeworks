#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getNum(void)
{
    int number = 0;
    while (true)
    {
        char symbol = 0;
        int input = scanf_s("%d%c", &number, &symbol);
        if (input == 2 && symbol == '\n' && number >= 0)
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
    int arraySize = 0;
    printf("Enter the length of the array: ");
    arraySize = getNum();
    int* arrayOfNumbers = malloc(arraySize * sizeof(int));

    printf("\nEnter the array elements one by one:\n");
    for (int i = 0; i < arraySize; i++)
    {
        int value = 0;
        printf("array[%d] = ", i);
        value = getNum();
        arrayOfNumbers[i] = value;
    }

    int zeroCounter = 0;
    for (int i = 0; i < arraySize; i++)\
    {
        if (arrayOfNumbers[i] == 0)
        {
            zeroCounter++;
        }
    }
    printf("\nThe number of zeros in the array: %d\n", zeroCounter);
}
