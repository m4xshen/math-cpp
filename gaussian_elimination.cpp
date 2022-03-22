#include <iostream>
using namespace std;

int first, second;
int identify(double matrixptr[][4]) { // 1:one solution 2:no solution 3:infinite solutions
    bool a = true, b = true, c = true;

    for(int i = 0; i < 3; i++) if(matrixptr[0][i] != matrixptr[1][i]) a = false;
    for(int i = 0; i < 3; i++) if(matrixptr[0][i] != matrixptr[2][i]) b = false;
    for(int i = 0; i < 3; i++) if(matrixptr[1][i] != matrixptr[2][i]) c = false;

    if(a && b && c) {
	if(matrixptr[0][3] == matrixptr[1][3] && matrixptr[1][3] == matrixptr[2][3]) {
	    cout << "\nInfinite Solutions\n";
	    cout << matrixptr[0][0] << "x + "
		 << matrixptr[0][1] << "y + "
		 << matrixptr[0][2] << "z = "
		 << matrixptr[0][3] << "\n";
	    return 4;
	}
	return 2;
    }
    else if(a || b || c) {
	if(a && matrixptr[0][3] == matrixptr[1][3]) {
	    first = 0, second = 2;
	    return 3;
	}
	else if(b && matrixptr[0][3] == matrixptr[2][3]) {
	    first = 0, second = 3;
	    return 3;
	}
	else if(c && matrixptr[1][3] == matrixptr[2][3]) {
	    first = 0, second = 1;
	    return 3;
	}
	return 2;
    }

    return 1;
}

int main() {
    double x, y, z, temp;
    double matrix[3][4];

    for(int i = 0; i < 3; i++) {
	for(int j = 0; j < 4; j++) {
	    cin >> matrix[i][j];

	    if(j == 0) {
		temp = matrix[i][j];
		matrix[i][j] = 1;
	    }
	    else matrix[i][j] /= temp;
	}
    }

    if(identify(matrix) == 4) return 0;
    else if(identify(matrix) == 3) {
	cout << "\nInfinite Solutions\n";

	for(int i = 0; i < 4; i++) {
	    matrix[second][i] -= matrix[first][i];
	}

	temp = matrix[first][1] / matrix[second][1];
	for(int i = 0; i < 4; i++) {
	    matrix[first][i] -= matrix[second][i]*temp;
	}

	cout << "x = " << matrix[first][3];
	if(matrix[first][2]*(-1) >= 0) cout << "+";
	cout << matrix[first][2]*(-1) << "t\n";

	cout << "y = " << matrix[second][3]/matrix[second][1];
	if(matrix[second][2]/matrix[second][1]*(-1) >= 0) cout << "+";
	cout << matrix[second][2]/matrix[second][1]*(-1) << "t\n";

	cout << "z = t\n";
    }
    else if (identify(matrix) == 2) cout << "\nNo Solution\n";
    else {
	for(int i = 0; i < 4; i++) {
	    matrix[1][i] -= matrix[0][i];
	    matrix[2][i] -= matrix[0][i];
	}

	temp = matrix[2][1] / matrix[1][1];
	for(int i = 0; i < 4; i++) matrix[2][i] -= matrix[1][i]*temp;

	temp = matrix[1][1];
	for(int i = 0; i < 4; i++) matrix[1][i] /= temp;

	if(matrix[2][2] == 0 && matrix[2][3] != 0) {
	    cout << "\nNo Solution\n";
	}
	else if(matrix[2][2] == 0 && matrix[2][3] == 0) {
	    cout << "\nInfinite Solutions\n";

	    temp = matrix[0][1] / matrix[1][1];
	    for(int i = 1; i < 4; i++) {
		matrix[0][i] -= matrix[1][i]*temp;
	    }

	    cout << "x = " << matrix[0][3];
	    if(matrix[0][2]*(-1) >= 0) std::cout << "+";
	    cout << matrix[0][2]*(-1) << "t\n";

	    cout << "y = " << matrix[1][3]/matrix[1][1];
	    if(matrix[1][2]/matrix[1][1]*(-1) >= 0) cout << "+";
	    cout << matrix[1][2]/matrix[1][1]*(-1) << "t\n" ;

	    cout << "z = t\n";
	}
	else {
	    z = matrix[2][3] / matrix[2][2];
	    y = (matrix[1][3]-matrix[1][2]*z) / matrix[1][1];
	    x = (matrix[0][3]-(matrix[0][1]*y)-(matrix[0][2]*z));

	    cout << "\nx = " << x << "\n";
	    cout << "y = " << y << "\n";
	    cout << "z = " << z << "\n";
	}
    }

    return 0;
}
