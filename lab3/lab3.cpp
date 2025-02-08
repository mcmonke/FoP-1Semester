#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    char ch;
    
    do {
        int x;
        int n;
        long double y = 1;
        long double elementLast = y;

        cout << "Введите: n:\n";
        cin >> n;
        cout << "Введите x:\n";
        cin >> x;
        
        for (int i = 1; i <= n; ++i) {
            long double elementNew = elementLast * (x*x) / (48*n*n - 2*n);
            y += elementNew;
            elementLast = elementNew;

            if (i == 3) { 
                cout << "n = 3, y = " << setprecision(6) << y << "\n";
            } else if (i == 5) {
                cout << "n = 5, y = " << setprecision(6) << y << "\n";
            } else if (i == 10) {
                cout << "n = 10, y = " << setprecision(6) << y << "\n";
            }
        }

        cout << "Результат: " << setprecision(6) << y << "\n";
        cout << "Продолжить? (y/n) \n";
        cin >> ch;
    } while (ch == 'y');
}


