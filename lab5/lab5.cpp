#include <iostream>
#include "Randomizer.h"
#include "functs.h"
#include "functs.cpp"
#include "Randomizer.cpp"
#include <iomanip>

int main(){
    Randomize();

    int n = 5;
    int* arr = CreateArray(n);

    std::cout<< "Количество элементов: "<< n <<". Заданный массив: " ;
    printArray(arr, n);
    std::cout<< "Сортировка по возрастанию \n" ;
    std::cout<<"Метод" << std::setw(29) <<  "Результат" << std::setw(25) << "Сравнений" << std::setw(31) << "Перестановок" << "\n";

    int compCount;
    int swapCount;
    int* aCopy1;
    int* aCopy2;

    aCopy1 = CopyArray(arr, n);
    aCopy2 = CopyArray(arr, n);

    selectionSort(aCopy2, n, compCount, swapCount, true);
    std::cout<<"сравнений (n)" << std::setw(4);
    printArray(aCopy2, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    selectionSort(aCopy2, n, compCount, swapCount, true);
    std::cout<<"сравнений (о)" << std::setw(4);
    printArray(aCopy2, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    bubleSort(aCopy1, n, compCount, swapCount, true);
    std::cout<<"пузырек (n)" << std::setw(6);
    printArray(aCopy1, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    bubleSort(aCopy1, n, compCount, swapCount, true);
    std::cout<<"пузырек (о)" << std::setw(6);
    printArray(aCopy1, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";
    std::cout<< '\n';
    
    
    std::cout<< "Количество элементов: "<< n <<". Заданный массив: " ;
    printArray(aCopy1, n);
    std::cout<< "Сортировка по убыванию \n" ;
    std::cout<<"Метод" << std::setw(29) <<  "Результат" << std::setw(25) << "Сравнений" << std::setw(31) << "Перестановок" << "\n";

    selectionSort(aCopy1, n, compCount, swapCount, false);
    std::cout<<"сравнений (n)" << std::setw(4);
    printArray(aCopy1, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    selectionSort(aCopy1, n, compCount, swapCount, false);
    std::cout<<"сравнений (о)" << std::setw(4);
    printArray(aCopy1, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";


    bubleSort(aCopy2, n, compCount, swapCount, false);
    std::cout<<"пузырек (n)" << std::setw(6);
    printArray(aCopy2, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    bubleSort(aCopy2, n, compCount, swapCount, false);
    std::cout<<"пузырек (о)" << std::setw(6);
    printArray(aCopy2, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";
    std::cout<< '\n';


    std::cout<< "Количество элементов: "<< n <<". Заданный массив: " ;
    printArray(arr, n);
    std::cout<< "Сортировка по убыванию \n" ;
    std::cout<<"Метод" << std::setw(29) <<  "Результат" << std::setw(25) << "Сравнений" << std::setw(31) << "Перестановок" << "\n";

    int* aCopy3;
    int* aCopy4;

    aCopy3 = CopyArray(arr, n);
    aCopy4 = CopyArray(arr, n);

    selectionSort(aCopy3, n, compCount, swapCount, false);
    std::cout<<"сравнений (n)" << std::setw(4);
    printArray(aCopy3, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    selectionSort(aCopy3, n, compCount, swapCount, false);
    std::cout<<"сравнений (о)" << std::setw(4);
    printArray(aCopy3, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";


    bubleSort(aCopy4, n, compCount, swapCount, false);
    std::cout<<"пузырек (n)" << std::setw(6);
    printArray(aCopy4, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    bubleSort(aCopy4, n, compCount, swapCount, false);
    std::cout<<"пузырек (о)" << std::setw(6);
    printArray(aCopy4, n);
    std::cout << std::setw(8) << compCount << std::setw(15) << swapCount << "\n";

    int* arr5 = CreateArray(5);
    int* arr50 = CreateArray(50);
    int* arr500 = CreateArray(500);

    std::cout<< '\n';
    std::cout<< "Метод: сравнений (n). Сортировка по возрастанию\n" ;
    std::cout<< "N"<< std::setw(33)<< "Сравнений"<< std::setw(34)<<"Перестановок  \n";
    selectionSort(arr5, 5, compCount, swapCount, true);
    std::cout<< "5"<< std::setw(17)<< compCount<< std::setw(15)<<swapCount<< "\n";
    selectionSort(arr50, 50, compCount, swapCount, true);
    std::cout<< "50"<< std::setw(18)<< compCount<< std::setw(14)<<swapCount<< "\n";
    selectionSort(arr500, 500, compCount, swapCount, true);
    std::cout<< "500"<< std::setw(19)<< compCount<< std::setw(13)<<swapCount<< "\n";


    int* arr1_5 = CreateArray(5);
    int* arr1_50 = CreateArray(50);
    int* arr1_500 = CreateArray(500);

    std::cout<< '\n';
    std::cout<< "Метод: пузырек (n). Сортировка по возрастанию\n" ;
    std::cout<< "N"<< std::setw(33)<< "Сравнений"<< std::setw(34)<<"Перестановок  \n";
    bubleSort(arr1_5, 5, compCount, swapCount, true);
    std::cout<< "5"<< std::setw(17)<< compCount<< std::setw(15)<<swapCount<< "\n";
    bubleSort(arr1_50, 50, compCount, swapCount, true);
    std::cout<< "50"<< std::setw(18)<< compCount<< std::setw(15)<<swapCount<< "\n";
    bubleSort(arr1_500, 500, compCount, swapCount, true);
    std::cout<< "500"<< std::setw(19)<< compCount<< std::setw(15)<<swapCount<< "\n";
    
}