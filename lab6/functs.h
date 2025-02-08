#include <iostream>

typedef double (*TPF)(double);
typedef double (*TPM)(TPF f, double a, double b, int n);

double IntRect(TPF f, double a, double b, int n);
double IntTrap(TPF f, double a, double b, int n);
double Integrate(TPF f, TPM method, double a, double b, double eps, int &n);

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);

struct I_print {const char *name; double i_sum; double i_toch; int n;};
void PrintTabl(I_print i_prn[], int k);
void Call(TPM method);

void Randomize();
int iRandom(int, int);

I_print printData[4];