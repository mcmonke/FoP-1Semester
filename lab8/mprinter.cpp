#include <iostream>
#include <iomanip>
#include "mprinter.h"

using namespace std;

const int dlinavivoda = 80;

void stringofrazdeliteley(char radelitel, int skokaotstup){
    int skokaznakov = (80/skokaotstup) * skokaotstup;
    for(int i = 0; i < skokaznakov; ++i){
        cout << radelitel;
    }
    cout << endl;
}

void mprint(double** matx, int n, int m, int precision, bool expanenta1fixed0){

    int skokaotstup;

    if(expanenta1fixed0 == 0){
        cout << setprecision(precision) << fixed;
        skokaotstup = precision + 6;
    } else {
        cout << setprecision(precision) << scientific;
        skokaotstup = precision + 10;
    }

    bool konec = 0;

    int skokaColumnInHorisontal = 0;
    bool isNotAll = true;
    int skokaColumnVsegoNow = 0;
    stringofrazdeliteley('=', skokaotstup);
    while (isNotAll){
        isNotAll = false;
        int skokaColumnInPreviousHorisontals = skokaColumnVsegoNow;
        for (int i = 0; i < n; i++){
            skokaColumnInHorisontal = 0;
            for (int j = skokaColumnInPreviousHorisontals; j < m; j++){
                std::cout << std::setw(skokaotstup) << matx[i][j];
                skokaColumnInHorisontal++;
                if (j == m-1){
                    konec=1;
                    break;
                }
                if (skokaotstup * skokaColumnInHorisontal > (dlinavivoda-skokaotstup)){
                    skokaColumnVsegoNow = skokaColumnInHorisontal + skokaColumnInPreviousHorisontals;
                    isNotAll = true;
                    break;
                }
            }
            std::cout << "\n";
        }
        if (isNotAll && (konec != 1)){
            stringofrazdeliteley('-', skokaotstup);
        } else { 
            stringofrazdeliteley('=', skokaotstup);
            break;
        }
    }
}

void printStaticMatrix(double B[][10]) {
    double** matrix = new double* [10];

    for (int i = 0; i < 10; i++){
        matrix[i] = new double[10];
        for (int j = 0; j < 10; j++){
            matrix[i][j] = B[i][j];
        }
    }
   mprint(matrix, 10, 10, 0, false);
}
