#include <iostream>
#include <string.h>

using namespace std;

int** creatematx(int n){
    int** matx = new int*[n];
    for(int i = 0; i < n; ++i){
        matx[i] = new int[n];
    }
    return matx;
}

void fillmatx(int** matx, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            matx[i][j] = (i + j);
            cout << matx[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return;
}

int findn(int** matx, int n){
    int max = matx[0][0];
    int stolb = 0;
    for(int i = 0; i < n; ++i){
        if (matx[i][i] > max){
            max = matx[i][i];
            stolb = i;
        }
    }
    return stolb;
} 

void printdown(int** matx, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i>j){
                cout << matx[i][j] << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << endl;
    }
}

void deletemem(int** matx, int n){
    for(int i = 0; i < n; ++i){
        delete[] matx[i];
    }
    delete[] matx;
}

int* createdinam(int n){
    int* mas = new int[n];
    for(int i = 0; i < n; ++i){
        mas[i] = i;
    }
    return mas;
}

void addelem(int*& mas, int &n, int m){
    int* temp = new int[n+1];
    for(int i = 0; i < n; ++i){
        temp[i] = mas[i];
    }
    temp[n] = m;
    delete[] mas;
    mas = temp;
    ++n;
}

void printmas(int* mas, int n){
    for(int i = 0; i < n; ++i){
        cout << mas[i] << ' ';
    }
}

int main(){
    int n = 5;
    cout << endl;

    int* mas = createdinam(n);
    addelem(mas, n, 5);
    addelem(mas, n, 6);
    addelem(mas, n, 7);
    addelem(mas, n, 8);
    addelem(mas, n, 9);
    mas[n+1] = 10;
    printmas(mas, n);

    cout << endl << mas[n+2];

    delete[] mas;
    return 0;
}