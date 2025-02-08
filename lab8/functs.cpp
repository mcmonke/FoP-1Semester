#include <iostream>
#include <cmath>
#include "functs.h"

using namespace std;

double** newmatx(int n, int m){
    double** matrix = new double*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new double[m];
    }
    return matrix;
}

void fillmatrix(double** matrix, int N, int M){
    for (int i = 0; i < N; i++){
        long lastFactorial = 1;
        int x = 1;
        for (int j = 0; j < M; j++){
            lastFactorial = lastFactorial * (j+1);
            if (i==j) {
                matrix[i][j] = 1.0;
            } else if (j > i){
                matrix[i][j] = (std::pow(x, (i+1))/(std::pow(lastFactorial, (i+1))));
                //matrix[i][j] = std::pow(x, i) / std::pow(fact(j), i);
            } else if (i > j){
                matrix[i][j] = (std::pow(-x, (i+1))/(std::pow(lastFactorial, (i+1))));
                //smatrix[i][j] = std::pow(-x, i) / std::pow(fact(j), i);
            }
        }
    }
}


void clearmemory(double** matx, int n){
    for(int i = 0; i < n; ++i){
        delete[] matx[i];
    }
    delete[] matx;
}

void fillNonDinamicMatrix(double matx[][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matx[i][j] = i * 10 + j;
        }
    }
}