#include <iostream> 
#include "menu.h"

int menu(){
    std::cout << "Меню: \n";
    
    std::cout << "1 - добавление слова в словарь \n"
        << "2 - удаление слова из словаря \n"
        << "3 - перевод слов с английского на русский \n"
        << "4 - перевод слов с русского на английский \n"
        << "5 - вывод на экран словаря  \n"
        << "6 - вывод словаря в файл \n"
        << "7 - выход из программы\n";

    std::cout << "\nВведите число от 1 до 7: ";
    int choose;

    if (std::cin >> choose) {
    } else {
        std::cin.clear(); // put the stream back into a good state
        std::cin.ignore(1000, '\n'); // and remove the bad input remaining in the input buffer
    }
    return choose;
}