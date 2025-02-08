#include <iostream>
#include "functs.cpp"
#include "mprinter.cpp"
#include <time.h>						                //time
#include <stdlib.h> 					                //srand, rand

using namespace std;

void Randomize() {						                
    srand((unsigned int)time(NULL));                    //	начальное число - время
    rand();                                             //  сброс первого числа, чтобы не повторялось,
}

int iRandom(int a, int b){				                // целое из [a, b] 
    return rand()%(b-a+1) + a;
}

int main(){
    Randomize();

    int n;
    int m;
    int precision;
    bool typeoflook;

    cout << endl << "введите количество строк, столбцов, количество знаков после запятой, вид вывода: 1 - exp | 0 - fixed " << endl;
    cin >> n >> m >> precision >> typeoflook;

    double** matrix = newmatx(n,m);
    fillmatrix(matrix, n, m);

    mprint(matrix, n, m, precision, typeoflook);

    clearmemory(matrix, n);

    cout << endl << endl << "PART TWO!" << endl << endl;

    double B[10][10];

    fillNonDinamicMatrix(B);
    printStaticMatrix(B);

    cout<<B <<"  "<<B[0]<<"  "<<B[2]<<endl;
    cout<<B[0][0]<<"  "<<**B <<"  "<<*B[0]<<endl;
    cout<<*(*(B+1))<<"  "<<*B[1]<<endl;
    cout<<*(B[0]+1)<<"  " <<*(*B+1)<<endl;
    cout<<B[0][20]<<"  "<<*(B[0]+20)<<"  "<<*B[2]<<endl;

    return 0;
}