#include <iostream>
#include <cmath>
#include <iomanip>
#include "functs.h"
#include <time.h>						                //time
#include <stdlib.h> 					                //srand, rand

using namespace std;

double f1(double x){ 
    return x; 
} 
double f2(double x){ 
    return sin(22 * x); 
} 
double f3(double x){ 
    return x * x * x * x; 
} 
double f4(double x){ 
    return atan(x);
}

double IntRect(TPF frect, double a, double b, int n){
    double h = (b - a) * 1.0 / n;
    double result = 0.0;

    for (int i = 0; i < n; i++)
        result += frect(a + h * (i + 0.5)); // значение фции в правой границе отрезка
    result *= h;
    return result;
}
double IntTrap(TPF ftrap, double a, double b, int n){
    double width = (b - a) * 1.0 / n;
    double result = 0.0;
    double x1, x2, h;

    for (int i = 0; i < n; i++) {
        x1 = a + i * width;
        x2 = a + (i + 1) * width;
        h = x2 - x1;
        result += 0.5 * h * (ftrap(x1) + ftrap(x2));
    }

    return result;
}

void Call(TPM method, int a, int b){
    std::cout<< "a = " << a << ", b = " << b << '\n';

    double epss[5] = { 0.01, 0.001, 0.0001, 0.00001, 0.000001 };
    for (int epsInd = 0; epsInd < 5; epsInd++){
        std::cout<< "eps = " << epss[epsInd] << "." << '\n';

        int n0, n1, n2, n3;
        double IntSum[4] = {
            Integrate(f1, method, a, b, epss[epsInd], n0),
            Integrate(f2, method, a, b, epss[epsInd], n1),
            Integrate(f3, method, a, b, epss[epsInd], n2),
            Integrate(f4, method, a, b, epss[epsInd], n3)
        };

        int N[4] = {n0, n1, n2, n3};

        for (int i = 0; i < 4; i++) {
            printData[i].i_sum = IntSum[i];
            printData[i].n = N[i];
        }
        PrintTabl(printData, 4);
    }
}

double Integrate(TPF f, TPM methodint, double a, double b, double eps, int &n)
{
    n = 1; // число "элементарных" прямоугольников
    double diff;
    do {
        diff = abs(methodint(f, a, b, n) - methodint(f, a, b, n * 2));
        n = n * 2;
    } while (abs(diff) > eps);
    return methodint(f, a, b, n);
}

void PrintTabl(I_print i_prn[], int k) {
    const char SIDE_SYBMOL = '|';
    const char HORIZONTAL_SYBMOL = '-';
    const char CONNECTOR_SYBMOL = '+';

    const int m = 4;                // число столбцов таблицы
    int wn[m] = {19, 18, 18, 10};   // ширина столбцов таблицы
    char *title[m] = {(char *) "Function ", (char *) "Integral", (char *) "IntSum", (char *) "N "};
    int size[m];
    for (int i = 0; i < m; i++) {
        size[i] = (int) strlen(title[i]);
    }

    // шапка таблицы
    std::cout << CONNECTOR_SYBMOL << std::setfill(HORIZONTAL_SYBMOL);
    for (int j = 0; j < m - 1; j++)
        std::cout << std::setw(wn[j]) << CONNECTOR_SYBMOL;
    std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << '\n';

    std::cout << SIDE_SYBMOL;
    for (int j = 0; j < m; j++)
        std::cout << std::setw((wn[j] - size[j]) / 2) << std::setfill(' ') << ' ' << title[j]
             << std::setw((wn[j] - size[j]) / 2) << SIDE_SYBMOL;
    std::cout << '\n';
    // заполнение таблицы
    for (int i = 0; i < k; i++) {
        std::cout << CONNECTOR_SYBMOL << std::fixed;
        for (int j = 0; j < m - 1; j++)
            std::cout << std::setfill(HORIZONTAL_SYBMOL) << std::setw(wn[j]) << CONNECTOR_SYBMOL;
        std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << std::setfill(' ') << '\n';

        std::cout << SIDE_SYBMOL << std::setw((int) (wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
             << std::setw((int) (wn[0] -std::strlen(i_prn[i].name)) / 2) << SIDE_SYBMOL;
        std::cout << std::setw(wn[1] - 1) << std::setprecision(10) << i_prn[i].i_toch << SIDE_SYBMOL
             << std::setw(wn[2] - 1) << i_prn[i].i_sum << std::setprecision(6) << SIDE_SYBMOL
             << std::setw(wn[3] - 1) << i_prn[i].n << SIDE_SYBMOL << '\n';
    }

    // низ таблицы
    std::cout << CONNECTOR_SYBMOL << std::setfill(HORIZONTAL_SYBMOL);
    for (int j = 0; j < m - 1; j++)
        std::cout << std::setw(wn[j]) << CONNECTOR_SYBMOL;
    std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << std::setfill(' ') << '\n';
}

void Randomize() {						                //	начальное число - время
    srand((unsigned int)time(NULL));
}

int iRandom(int a, int b){				                // целое из [a, b] 
    return rand()%(b-a+1) + a;
}