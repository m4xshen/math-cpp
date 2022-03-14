#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

#define precision 0.000001
double coefficients[100];
int degree = -1, count = 1;

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
    string input, buffer;

    cout << "Please input a polynominal: ";
    getline(cin, input);
    stringstream ss(input);
    while(ss >> buffer) degree++;

    ss.str("");
    ss.clear();
    ss << input;

    for(int i = degree; i >= 0; i--) {
	ss >> buffer;
	coefficients[i] = stoi(buffer);
    }

    cout << "Please input a1: ";
    cin >> a1;
    newton(a1);

    return 0;
}
