#include <iostream>
#include <iomanip>

double f(double x, double k){
    return x - k * cos(x);
}
double f1(double x, double k){
    return 1 + k * sin(x);
}
double g(double x, int k){
    return x - f(x, k);
}

void newton(double eps, double k, int z){
    double x = 0;
    int n = 0;
    while (std::fabs(f(x, k)) > eps){
        x = x - (double)f(x, k) / f1(x, k);
        n++;
        if (n >= 100000)
            break;
    }
    std::cout << std::fixed << "3" << std::setprecision(z) << std::setw(22) << x << std::setw(9) << n << "\n";

}

void pereborom(double eps, int k, int z)
{
    int n = 0;
    double x = 0, oldx = 999999;
    while (abs(x - oldx) >= eps)
    {
        oldx = x;
        x = g(x, k);
        n += 1;
        if (n >= 100000)
            break;
    }
    std::cout << std::fixed << "1" << std::setw(22) << std::setprecision(z) << x << std::setw(9) << n << "\n";
}

void polovinnoe(double eps, int k, int z){
    int n = 0;
    double xr = 10;
    double xl = -10;
    while (abs(f((xr + xl) / 2, k)) >= eps)
    {
        if (f((xr + xl) / 2, k) > 0 && f(xr, k) < 0 || f((xr + xl) / 2, k) < 0 && f(xr, k) > 0)
            xl = (xr + xl) / 2;
        else if (f((xr + xl) / 2, k) > 0 && f(xl, k) < 0 || f((xr + xl) / 2, k) < 0 && f(xl, k) > 0)
            xr = (xr + xl) / 2;
        else if (n >= 100000)
        {
            return;
        }
        n++;
    }
    std::cout << std::fixed << "2" << std::setw(22) << std::setprecision(z) << (xr + xl) / 2 << std::setw(9) << n << "\n";
}
