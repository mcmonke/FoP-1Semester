#include <iostream>
#include <fstream>
#include <iomanip>

struct StatStruct {
    char16_t simbol;
    int sourceCount;
    int optionCount;
    int keysLen;
    int sourceLen;
    char lastCode;
};

void clearmemorymatrix(int**);
void countstatmat(int**, int*, int*); 
int** creatematrix();
void printMatrix(int**, int*, int*);

size_t getFileSize(const char*); 
size_t wordsCount(const char*);
char* readFile(const char*);
void writeFile(char, int, const char*);
int* getKeyArray(const char*);
char* encodeText(char*, int*, int, StatStruct*, int**);
char* decodeText(char*, int*,  int);
void countStats(StatStruct*, size_t, size_t, unsigned char, int);
void printStatTable(StatStruct*);
