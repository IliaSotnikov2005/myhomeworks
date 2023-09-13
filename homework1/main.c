#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 80
#define VALUE_SIZE 80

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

void reverse_array(char* array, int start, int length) {
	;
	for (int i = start; i < start + (length / 2); i++) {
		char temp = array[i];
		array[i] = array[start + length - 1 - (i - start)];
		array[start + length - 1 - (i - start)] = temp;
	}
}

void printArray(char* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s ", array[i]);
	}
	printf("\n");
}

int main()
{
	printf("Enter the size of array: ");
	int arraySize = getNum();
	char** array = (char**) malloc(arraySize * sizeof(char*));
	printf("\nEnter the array elements one by one:\n");
	for (int i = 0; i < arraySize; i++)
	{
		printf("array[%d] = ", i);
		char value[VALUE_SIZE] = { 0 };
		scanf_s("%s", &value);
		array[i] = (char*) malloc((strlen(value) + 1) * sizeof(char));
		strcpy(array[i], value);
	}

	int firstPartLength = 0;
	printf("\nEnter the length of the first segment: ");
	firstPartLength = getNum();
	while (firstPartLength > arraySize)
	{
		printf("\nThe length of the first part should be <= the length of the array (%d)\nTry again: ", arraySize);
		firstPartLength = getNum();
	}
	int secondPartLength = arraySize - firstPartLength;
	printf("\nThe length of the second segment is %d\n", secondPartLength);

	reverse_array(array, 0, firstPartLength);
	reverse_array(array, firstPartLength, secondPartLength);
	reverse_array(array, 0, firstPartLength + secondPartLength);
	printf("\nThe original array is\n");
	printArray(array, arraySize);
}
