#include <iostream>
#include "menu.cpp"
#include "mdict.cpp"
using namespace std;

int interactive(Dictionary *dict, int &num_w){

    cout << endl;
    
    addWord(dict, num_w, "plane", "samolet");
    addWord(dict, num_w, "sad", "grustno");
    addWord(dict, num_w, "house", "dom");
    addWord(dict, num_w, "number", "chislo");
    addWord(dict, num_w, "god", "bog");
    addWord(dict, num_w, "go", "idty");
    addWord(dict, num_w, "rose", "roza");
    addWord(dict, num_w, "do", "delaet");
    addWord(dict, num_w, "work", "rabotaet");
    addWord(dict, num_w, "lazy", "leniviy");

    cout << endl;

    while (true) {
        switch (menu()) {
            case 1:
                addWord(dict, num_w, "-", "-");
                break;
            case 2:
                deleteFromDict(dict, num_w, "-");
                break;
            case 3:
                translateFromEnglish(dict, num_w, "-");
                break;
            case 4:
                translateFromRussian(dict, num_w, "-");
                break;
            case 5:
                printDict(dict, num_w);
                break;
            case 6:
                writeToDict(dict, num_w);
                break;
            case 7:
                return 0;
            default:
                cout << "!!Надо вводить число от 1 до 7!!\n\n";
                break;
        }
    }
}

int demo(Dictionary *dict, int &num_w){

    addWord(dict, num_w, "house", "dom");
    addWord(dict, num_w, "garden", "sad");
    addWord(dict, num_w, "plane", "samolet");

    printDict(dict, num_w);

    deleteFromDict(dict, num_w, "house");

    printDict(dict, num_w);

    writeToDict(dict, num_w);

    translateFromEnglish(dict, num_w, "plane");
    translateFromRussian(dict, num_w, "samolet");

    return 0;
}