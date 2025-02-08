#include <iostream>
#include <fstream>

struct StatStruct {
    char16_t simbol;
    int sourceCount;
    int optionCount;
    int keysLen;
    int sourceLen;
    char lastCode;
};

size_t getFileSize(const char*); 
size_t wordsCount(const char*);
char* readFile(const char*);
void writeFile(char, int, const char*);
int* getKeyArray(const char*);
char* encodeText(char*, int*, int, StatStruct*);
char* decodeText(char*, int*,  int);
void countStats(StatStruct*, size_t, size_t, unsigned char, int);
void printStatTable(StatStruct*);
