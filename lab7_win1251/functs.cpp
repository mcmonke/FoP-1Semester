#include <iostream>
#include <fstream>
#include "functs.h"


using namespace std;

size_t getFileSize(const char* fileName){
    std::ifstream file( fileName, std::ios::binary | std::ios::ate );
    if (!file){ std::cout << "ќЎ»Ѕ ј!!! ‘айл '" << fileName << "' не найден.\n"; return 0;}
    size_t fileSize = file.tellg();
    file.close();
    return fileSize;
}

size_t wordsCount(const char* str){
    size_t i = 0, j = 0;
    while (str[i] != '\0'){
        if ((str[i] == ' ') || (int(str[i]) == 10)){
            if(i>=1){
                if((str[i-1] != ' ') && (int(str[i-1]) != 10)){
                    j++;
                }
            }
        }
        i++;
    }
    return j;
}

char* readFile(const char* fileName){
    size_t len = getFileSize(fileName);
    char* string = new char[len]; 
    std::ifstream file(fileName, std::ios::binary);
    if (!file){ std::cout << "ќЎ»Ѕ ј!!! ‘айл '" << fileName << "' не найден.\n"; return 0;}
    for (int i = 0; i < len; i++){
        file.get(string[i]);
    }
    file.close();
    return string;
}

void writeFile(char text[], int size, const char* filename){
    std::ofstream f;
    f.open(filename, std::ios::binary);
    for (int i = 0; i < size; i++)
        f << text[i];
    f.close();
}

int* getKeyArray(const char* str){
    int* codesArray = new int[wordsCount(str)];
    int curSimbolCode;
    int j = 0;
    for (int i = 0; i < strlen(str); i++){
        if ((str[i] == ' ') || (int(str[i]) == 10)){
            if(i>=1){
                if((str[i-1] != ' ') && (int(str[i-1]) != 10)){
                    codesArray[j] %= 256;
                    j++;
                }
            }
        }else{
            curSimbolCode = (int)str[i]; // код символа в таблице
            codesArray[j] += curSimbolCode;
        }
        codesArray[j] %= 256; 
    }
    return codesArray;
}

void countStats(StatStruct* stat, size_t sourceFileLen, size_t keyArrayLength, unsigned char sourceChar, int curSimbolCode){
    stat[sourceChar].keysLen = keyArrayLength;          //слов в словаре
    stat[sourceChar].sourceLen = sourceFileLen;         //букв в исходнике
    stat[sourceChar].simbol = sourceChar;               //символ
    stat[sourceChar].sourceCount += 1;                  //буква встречаетс€ в исходнике
    if (stat[sourceChar].lastCode != curSimbolCode){
        stat[sourceChar].optionCount++;
        stat[sourceChar].lastCode = curSimbolCode;      //кол-во вариаций изменений одной буквы 
    }
}

char* encodeText(char* sourceFile, int* keyArray, size_t keyArrayLength, StatStruct* stat){
    size_t len = strlen(sourceFile);
    char* encodedFile = new char[len];  
    int j = 0;

    for (int i = 0; i < len; i++){
        if ((sourceFile[i] == ' ') || (int(sourceFile[i]) == 10)){ 
            if(i>=1){
                if((sourceFile[i-1] != ' ') && (int(sourceFile[i-1]) != 10)){
                    j++;
                    if (j > keyArrayLength){
                        j = 0;
                    }
                }
            }
        }

        int curSimbolCode = ((int)sourceFile[i] + keyArray[j]);
        if (curSimbolCode > 256){ curSimbolCode = curSimbolCode - 256; }

        if ((sourceFile[i] != ' ') && (int(sourceFile[i]) != 10)){ 
            encodedFile[i] = char(curSimbolCode); 
        }else if(sourceFile[i] == ' '){
            encodedFile[i] = ' ';
        }else{
            encodedFile[i] = char(10);
        }

        int help = int(sourceFile[i]);
        
        countStats(stat, len, keyArrayLength, char(help), curSimbolCode);
    }
    return encodedFile;
}

char* decodeText(char* encodedText, int* keyArray, int keyArrayLength ){
    size_t len = strlen(encodedText);
    char* decodedFile = new char[len];  
    int j = 0;

    for (int i = 0; i < len; i++){
        if ((encodedText[i] == ' ') || (encodedText[i] == char(10))){
            if(i>=1){
                if((encodedText[i-1] != ' ') && (encodedText[i-1] != char(10))){ 
                    j++;
                    if (j >= keyArrayLength){
                        j = 0;
                    }
                }
            }
        }
        
        int curSimbolCode = ((int)encodedText[i] - keyArray[j]);
        if (curSimbolCode < 0){ curSimbolCode = curSimbolCode + 256; }

        if ((encodedText[i] != ' ') && (int(encodedText[i]) != 10)){ 
            decodedFile[i] = curSimbolCode;        
        }else if (int(encodedText[i]) == 10){
            decodedFile[i] = char(10);   
        }else if (encodedText[i] == ' '){
            decodedFile[i] = ' ';
        }
    }
    return decodedFile;
}

void printStatTable(StatStruct* stat){
    ofstream ivan("ivan.txt");
    ivan << "| символ | кол-во в исх-ом | кол-во в вар-ов | размер блокнота | длина исх-ый |\n";
    ivan << "|--------|-----------------|-----------------|-----------------|--------------|\n";
    std::cout << "| символ | кол-во в исх-ом | кол-во в вар-ов | размер блокнота | длина исх-ый |\n";
    std::cout << "|--------|-----------------|-----------------|-----------------|--------------|\n";
    for (int i = 0; i < 256;i++){
        if(stat[i].simbol && stat[i].simbol != char(10)){
            ivan << "|"<<std::setw(8)<<char(stat[i].simbol)<<"|"<<std::setw(17)<<stat[i].sourceCount<<"|"<<std::setw(17)<<stat[i].optionCount<<"|"<<std::setw(17)<<stat[i].keysLen<<"|"<<std::setw(14)<<stat[i].sourceLen<<"|\n";
            std::cout << "|"<<std::setw(8)<<char(stat[i].simbol)<<"|"<<std::setw(17)<<stat[i].sourceCount<<"|"<<std::setw(17)<<stat[i].optionCount<<"|"<<std::setw(17)<<stat[i].keysLen<<"|"<<std::setw(14)<<stat[i].sourceLen<<"|\n";
        }
    }
}
