#include <iostream>
#include <iomanip>
#include <cmath>
#include "functs.cpp"

int main(){

    Randomize();
    int a = iRandom(0,1);
    int b = iRandom(2,3);

    const char* functions[4] = {"y=x", "y=sin(22*x)", "y=x^4", "y=arctg(x) "}; // обозначения функций
    double Int[4] = { // точно посчитаные интегралы
        (b * b - a * a) / 2.0,
        (cos(a * 22.0) - cos(b * 22.0)) / 22.0,
        (b * b * b * b * b - a * a * a * a * a) / 5.0,
        (b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0)
    };

    for (int i = 0; i < 4; i++) {
            printData[i].name = functions[i];
            printData[i].i_toch = Int[i];
        }

    std::cout << "Метод прямоугольников. " << "\n";
    Call(IntRect, a, b);

    std::cout <<"\n\n " <<  "Метод трапеций. " << "\n";
    Call(IntTrap, a, b);
}
