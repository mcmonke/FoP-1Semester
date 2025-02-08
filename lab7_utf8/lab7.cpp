#include <iostream>
#include <fstream>
#include "functs.cpp"
using namespace std;
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream ivan("ivan.txt");

    char* sourceFile = readFile("source.txt");
    std::cout << "Содержимое source.txt: \n";
    std::cout << sourceFile << "\n" << "\n";
    ivan << "Содержимое source.txt: \n";
    ivan << sourceFile << "\n" << "\n";

    char* keyFile = readFile("key.txt");
    std::cout << "Содержимое key.txt: \n";
    std::cout << keyFile << "\n" << "\n";
    ivan << "Содержимое key.txt: \n";
    ivan << keyFile << "\n" << "\n";

    StatStruct* statsArray = new StatStruct[256];
    int** matrix = creatematrix();
    int* stroka = new int[128];
    int* stolb = new int[128];

    int* keyArray = getKeyArray(keyFile);
    char* encodedText = encodeText(sourceFile, keyArray, wordsCount(keyFile), statsArray, matrix);
    writeFile(encodedText, strlen(encodedText), "encoded.txt");
    char* encodedFile = readFile("encoded.txt");
    std::cout << "Содержимое encoded.txt: \n";
    std::cout << encodedFile << "\n\n";
    ivan << "Содержимое encoded.txt: \n";
    ivan << encodedFile << "\n\n";

    char* decodedText = decodeText(encodedText, keyArray, wordsCount(keyFile));
    writeFile(decodedText, strlen(decodedText), "decoded.txt");
    char* decodedFile = readFile("decoded.txt");
    std::cout << "Содержимое decoded.txt: \n";
    std::cout << decodedFile << "\n\n";
    ivan << "Содержимое decoded.txt: \n";
    ivan << decodedFile << "\n\n";
    
    printStatTable(statsArray);
    countstatmat(matrix, stroka, stolb);
    printMatrix(matrix, stroka, stolb);

    clearmemorymatrix(matrix);
    delete[] stolb;
    delete[] stroka;
}

