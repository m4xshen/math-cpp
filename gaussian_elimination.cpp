#include <iostream>

int identify(double matrixptr[][4]) { // 1:One Solution 2:No Solution 3:Infinite Solutions
    bool a = true, b = true, c = true;
    double matrix1[3][4];

    for(int i = 0; i < 3; i++) {
	double temp = matrixptr[i][0];
	for(int j = 0; j < 4; j++) {
	    matrix1[i][j] = matrixptr[i][j] / temp;
	}
    }    

    for(int i = 0; i < 3; i++) if(matrix1[0][i] != matrix1[1][i]) a = false;
    for(int i = 0; i < 3; i++) if(matrix1[0][i] != matrix1[2][i]) b = false;
    for(int i = 0; i < 3; i++) if(matrix1[1][i] != matrix1[2][i]) c = false;

    if(a && b && c) {
	if(matrix1[0][3] == matrix1[1][3] && matrix1[1][3] == matrix1[2][3]) {
	    std::cout << matrixptr[0][0] << "x + " << matrixptr[0][1] << "y + " << matrixptr[0][2] << "z = " << matrixptr[0][3] << std::endl;
	    return 3; //三平面重合
	}
	return 2;
    }
    else if(a || b || c) { //1:交於一直線
	if(a && matrix1[0][3] == matrix1[1][3]) return 3;
	else if(b && matrix1[0][3] == matrix1[2][3]) return 3;
	else if(c && matrix1[1][3] == matrix1[2][3]) return 3;
	return 2;
    }
    return 1;
}

int main() {
    double x, y, z;
    double matrix[3][4];

    for(int i = 0; i < 3; i++) {
	for(int j = 0; j < 4; j++) {
	    std::cin >> matrix[i][j];
	}
    }

    if(identify(matrix) == 3) std::cout << "infinite solutions" << std::endl;
    else if(identify(matrix) == 2) std::cout << "no solution" << std::endl;
    else {
	double temp = matrix[0][0];
	for(int i = 0; i < 4; i++) matrix[0][i] /= temp; //第一列的x係數變為1

	temp = matrix[1][0] / matrix[0][0];
	for(int i = 0; i < 4; i++) matrix[1][i] -= matrix[0][i]*temp; //第二列x係數變為0

	temp = matrix[2][0] / matrix[0][0];
	for(int i = 0; i < 4; i++) matrix[2][i] -= matrix[0][i]*temp; //第三列x係數變為0

	temp = matrix[2][1] / matrix[1][1];
	for(int i = 0; i < 4; i++) matrix[2][i] -= matrix[1][i]*temp;

	temp = matrix[1][1];
	for(int i = 0; i < 4; i++) matrix[1][i] /= temp; //第二列y係數變為1

	std::cout << std::endl;
	for(int i = 0; i < 3; i++) {
	    for(int j = 0; j < 4; j++) {
		std::cout << matrix[i][j] << "\t";
	    }
	    std::cout << std::endl;
	}

	if(matrix[2][2] == 0 && matrix[2][3] != 0) {
	    std::cout << "no solution" << std::endl;
	}
	else if(matrix[2][2] == 0 && matrix[2][3] == 0) {
	    std::cout << "infinite solutions" << std::endl;
	}
	else {
	    z = matrix[2][3] / matrix[2][2];
	    y = (matrix[1][3]-matrix[1][2]*z) / matrix[1][1];
	    x = (matrix[0][3]-(matrix[0][1]*y)-(matrix[0][2]*z));

	    std::cout << std::endl;
	    std::cout << "x = " << x << std::endl;
	    std::cout << "y = " << y << std::endl;
	    std::cout << "z = " << z << std::endl;
	}
    }

    return 0;
}

/*

   2 -1 1 -4
   1 1 2 1
   3 5 9 8

   x = -2
   y = 1
   z = 1

*/
