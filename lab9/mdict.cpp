#include <iostream>
#include <fstream>
#include "mdict.h"
using namespace std;

int compare(char *word1, char *word2){
    for (int i = 0; word1[i] != '\0' || word2[i] != '\0'; i++)
        if (word1[i] > word2[i])
            return 1;
        else if (word1[i] < word2[i])
            return -1;
    return 0;
}


void addWord(Dictionary *dict, int &num_w, const char *eng, const char *ru){
    char *word;
    char *translate;

    if (eng[0] != '-' and ru[0] != '-'){
        word = new char[strlen(eng)+1];
        strcpy(word, eng);
        translate = new char[strlen(ru)+1];
        strcpy(translate, ru);
    }else{
        cout << "Введите английское слово - ";
        char tmp[30];
        cin >> tmp;
        word = new char[strlen(tmp)+1];
        strcpy(word, tmp);

        cout << "Введите перевод слова на русском языке'" << word << "' - ";
        cin >> tmp;
        translate = new char[strlen(tmp)+1];
        strcpy(translate, tmp);
    }

    int indexToWrite = num_w;
    for (int i = 0; i < num_w-1;i++){

        if (compare(word, dict[i].engl) == 0 or compare(word, dict[i+1].engl) == 0){
            cout << "Слово '"<< word << "' уже есть в словаре\n\n";
            return;
        }

        if (i == 0 and compare(word, dict[i].engl) == -1){
            indexToWrite = i; 
            break;
        }
        if (compare(word, dict[i].engl) == 1 && compare(word, dict[i+1].engl) == -1){
            indexToWrite = i+1; 
            break;
        }

    }
    
    if (indexToWrite == num_w){
        dict[num_w].engl = word;
        dict[num_w].rus = translate;
        num_w++;
    }else{
        num_w++;
        for (int i = num_w - 1; i >= indexToWrite; i--){
            dict[i] = dict[i-1];
        }
        dict[indexToWrite].engl = word;
        dict[indexToWrite].rus = translate;
    }
    cout << "Слово " << word << " успешно добавлено в словарь." << "\n";
}


void deleteFromDict(Dictionary *dict, int &num_w,const char *eng){

    char *target;
    if (eng[0] != '-'){
        target = new char[strlen(eng)+1];
        strcpy(target, eng);
    }else{
        cout << "Введити английское слово для поиска: ";
        char tmp[30];
        cin >> tmp;
        target = new char[strlen(tmp)+1];
        strcpy(target, tmp);
    }


    int leftside = 0;
    int rightside = num_w-1;
    int findedIndex = -1;

    for(int i = 0; i < num_w; ++i){
        int comp = compare(target, dict[i].engl);
        if (comp == 0){
            findedIndex = i;
            break;
        }
    }

    if(findedIndex != -1){
        delete dict[findedIndex].engl;
        delete dict[findedIndex].rus;

        for (int i = findedIndex; i < num_w; i++)
            dict[i] = dict[i+1];
        num_w--;
        cout <<"Слово '"<< target<<"' удалено \n\n";
    }else{
        cout <<"Слово '"<< target<<"' не найдено в словаре \n\n";
        return;
    }

}


void printDict(Dictionary *dict, int &num_w){
    for (int i = 0; i < num_w; i++){
            cout << i + 1 << ". " << dict[i].engl << " " << dict[i].rus << "\n";
    }
    cout << "\n";
}


void writeToDict(Dictionary *dict, int &num_w){
    ofstream f("dict.txt", ios::binary);

    for (int i = 0; i < num_w; i++){
        f << dict[i].engl << " " << dict[i].rus << "\n";
    }

    f.close();

    cout << "Словарь напечатан в файл 'dict.txt'" << "\n\n";
}


void translateFromEnglish(Dictionary *dict, int &num_w,const char *eng){
    char *target = new char();

    if (eng[0] != '-'){
        target = new char[strlen(eng)+1];
        strcpy(target, eng);
    }else{
        cout << "Введити английское слово для поиска: ";
        char tmp[30];
        cin >> tmp;
        target = new char[strlen(tmp)+1];
        strcpy(target, tmp);
    }

    int left = 0;
    int right = num_w-1;
    int mid;

    while (left <= right){
        mid = (left + right)/2;
        if (compare(dict[mid].engl,target)==0) {
            cout <<"Слово '"<< target<< "' переводится как - '" <<  dict[mid].rus << "'\n\n";
            return;
        } else if (compare(dict[mid].engl,target)==(-1)) {
            left = mid + 1;
        } else if (compare(dict[mid].engl,target)==(1)) {
            right = mid - 1;
        }
    }
    cout <<"Слово '"<< target<<"' не найдено в словаре, \n";
    for (int i = 0; i < num_w; i++){
        if (compare(dict[i].rus, target) == 0){
            cout << "но оно принадлежит русскому словарю, перевести с русского на английский?\n";
            cout << "y - yes | Any other key - no\n";
            char bulka;
            cin >> bulka;
            if(bulka == 'y' || bulka == 'Y'){
                cout <<"Слово '"<< target<< "' переводится как - '" <<  dict[i].engl << "'\n\n";
                return;
            } else {
                return;
            }
        }
    }
    return;
}


void translateFromRussian(Dictionary *dict, int &num_w,const char *ru){
    char *target = new char();

    if (ru[0] != '-'){
        target = new char[strlen(ru)+1];
        strcpy(target, ru);
    }else{
        cout << "Введити слово для поиска: ";
        char tmp[30];
        cin >> tmp;
        target = new char[strlen(tmp)+1];
        strcpy(target, tmp);
    }

    for (int i = 0; i < num_w; i++){
        if (compare(dict[i].rus, target) == 0){
            cout <<"Слово '"<< target<< "' переводится как - '" <<  dict[i].engl << "'\n\n";
            return;
        }
    }
    
    cout <<"Слово '"<<target<<"' не найдено в словаре \n\n";
    return;
}
