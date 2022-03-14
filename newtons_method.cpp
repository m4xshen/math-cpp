#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define precision 0.000001
double coefficients[100];
int degree, count = 1;

double f(double x) {
    double total = 0;

    for(int i = degree; i >= 0; i--) {
	total += coefficients[i] * pow(x, i);
    }

    return total;
}

double df(double x) {
    double total = 0;

    for(int i = degree; i >= 0; i--) {
	total += coefficients[i] * i * pow(x, i-1);
    }

    return total;
}

double newton(double a) {
    double aNext = a - f(a)/df(a);
    cout << "a" << count++ << " = " << a << "\n";

    return (abs(aNext - a) <= precision) ? aNext : newton(aNext);
}

int main() {
    double a1;

    cout << "Please input the degree of the polynominal: ";
    cin >> degree;

    cout << "Please input coefficients: ";
    for(int i = degree; i >= 0; i--) cin >> coefficients[i];

    cout << "Please input a1: ";
    cin >> a1;
    newton(a1);

    return 0;
}
