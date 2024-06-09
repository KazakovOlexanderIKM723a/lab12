#include <iostream>
#include <cstdlib>

using namespace std;

void findMinElement(int** matrix, int n, int& minRow, int& minCol) {
    int minElement = matrix[0][0];
    minRow = 0;
    minCol = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
}


void swapRowAndColumn(int** matrix, int row, int col, int n) {
    for (int i = 0; i < n; ++i) {
        int temp = matrix[row][i];
        matrix[row][i] = matrix[i][col];
        matrix[i][col] = temp;
    }
}


void sortSecondRowDescending(int** matrix, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (matrix[1][j] < matrix[1][j + 1]) {
                    int temp = matrix[1][j];
                    matrix[1][j] = matrix[1][j + 1];
                    matrix[1][j + 1] = temp;
                }
            }
        }
    }
}


void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
   
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    
    cout << "Enter element of matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << "Initial matrix:" << std::endl;
    printMatrix(matrix, n);
    
    int minRow, minCol;
    findMinElement(matrix, n, minRow, minCol);

    
    swapRowAndColumn(matrix, minRow, minCol, n);

    
    sortSecondRowDescending(matrix, n);

    
    cout << "The resulting matrix:" << endl;
    printMatrix(matrix, n);

    
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

