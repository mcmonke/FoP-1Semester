#include "functs.h"
#include "Randomizer.h"
#include <stdio.h>

int* CreateArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = iRandom(0, 9);
	return arr;
}

int* CopyArray(int* source, int size) {
	int* newArr = new int[size];
	for (int i = 0; i < size; ++i)
		newArr[i] = source[i];
	return newArr;
}

void printArray(int* arr, const int size)
{
	for (int i = 0; i < size; i++){
		    std::cout << *(arr+i) << " ";
	}
}

void selectionSort(int* arr, const int size, int& compCount, int& swapCount, bool flag)
{
    swapCount = compCount = 0;
	int fixed;
    for (int i = 0; i < size - 1; i++) {
        fixed = i;
        for (int j = i + 1; j < size; j++) {
            compCount++;
            if (arr[j] < arr[fixed] && flag || arr[j] > arr[fixed] && !flag)
                fixed = j;
        }
        if (fixed != i) {
            std::swap(arr[fixed], arr[i]);
            swapCount++;
        }
    }
}

void bubleSort(int* array, const int size, int& com, int& sw, bool flag)
{
    sw = 0, com = 0;
    bool array_sorted;
    for (int i = 0; i < size - 1; i++)
    {
        array_sorted = true;
        for (int j = 0; j < size - i - 1; j++)
        {
           com++;
            if (array[j] > array[j + 1] && flag || array[j] < array[j + 1] && !flag)
            {
                array_sorted = false;
                std::swap(array[j], array[j + 1]);
                sw++;
            }
            
        }	
        if (array_sorted)
            break;
    }
}