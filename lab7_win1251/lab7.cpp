#include <iostream>
#include <fstream>
#include "functs.cpp"
using namespace std;
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream ivan("ivan.txt");

    char* sourceFile = readFile("source.txt");
    std::cout << "���������� source.txt: \n";
    std::cout << sourceFile << "\n" << "\n";
    ivan << "���������� source.txt: \n";
    ivan << sourceFile << "\n" << "\n";

    char* keyFile = readFile("key.txt");
    std::cout << "���������� key.txt: \n";
    std::cout << keyFile << "\n" << "\n";
    ivan << "���������� key.txt: \n";
    ivan << keyFile << "\n" << "\n";

    StatStruct* statsArray = new StatStruct[256];

    int* keyArray = getKeyArray(keyFile);
    char* encodedText = encodeText(sourceFile, keyArray, wordsCount(keyFile), statsArray);
    writeFile(encodedText, strlen(encodedText), "encoded.txt");
    char* encodedFile = readFile("encoded.txt");
    std::cout << "���������� encoded.txt: \n";
    std::cout << encodedFile << "\n\n";
    ivan << "���������� encoded.txt: \n";
    ivan << encodedFile << "\n\n";

    char* decodedText = decodeText(encodedText, keyArray, wordsCount(keyFile));
    writeFile(decodedText, strlen(decodedText), "decoded.txt");
    char* decodedFile = readFile("decoded.txt");
    std::cout << "���������� decoded.txt: \n";
    std::cout << decodedFile << "\n\n";
    ivan << "���������� decoded.txt: \n";
    ivan << decodedFile << "\n\n";
    
    printStatTable(statsArray);
}
