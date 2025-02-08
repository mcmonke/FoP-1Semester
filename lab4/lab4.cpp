#include <iostream>
#include <iomanip>
#include "functs.h"
#include "functs.cpp"

int main(){
    std::cout << "Уравнение: x - cos(x) = 0. Погрешность: 0.000001 \n";
    std::cout << "№ метода" << std::setw(6) << "x" << std::setw(20) <<"N \n";
    pereborom(0.000001, 1, 8);
    polovinnoe(0.000001, 1, 8);
    newton(0.000001, 1, 8);

    std::cout << "Уравнение: x - cos(x) = 0. Погрешность: 0.0000001 \n";
    std::cout << "№ метода" << std::setw(6) << "x" << std::setw(20) <<"N \n";
    pereborom(0.000001, 1, 10);
    polovinnoe(0.000001, 1, 10);
    newton(0.000001, 1, 10);
    
    std::cout << "Уравнение: x - k * cos(x) = 0, k = 5. Погрешность: 0.000001 \n";
    std::cout << "№ метода" << std::setw(6) << "x" << std::setw(20) <<"N \n";
    pereborom(0.00000001, 5, 8);
    polovinnoe(0.00000001, 5, 8);
    newton(0.00000001, 5, 8);

    std::cout << "Уравнение: x - k * cos(x) = 0, k = 10. Погрешность: 0.000001 \n";
    std::cout << "№ метода" << std::setw(6) << "x" << std::setw(20) <<"N \n";
    pereborom(0.0000001, 10, 8);
    polovinnoe(0.0000001, 10, 8);
    newton(0.0000001, 10, 8);
}
