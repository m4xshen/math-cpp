#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

double coefficients[100];
int degree;

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

double newton(double n) {
    double next;
    next = n - f(n)/df(n);
    cout << n << "\n";

    return (abs(f(n) / df(n)) <= 0.000001) ? next : newton(next);
}

int main() {
    double start;

    cout << "Please input the degree of the polynominal:";
    cin >> degree;

    cout << "Please input coefficients:";
    for(int i = degree; i >= 0; i--) cin >> coefficients[i];

    cout << "Please input starting point:";

    cin >> start;
    newton(start);

    return 0;
}
