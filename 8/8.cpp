#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int findMax(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMin(const int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

void replaceValue(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            arr[i] = 0;
        }
    }
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;

    ifstream input("input.txt");
    if (!input) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    input >> n >> m;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input >> matrix[i][j];
        }
    }
    input.close();

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix, n, m);

    for (int j = 0; j < m; j++) {
        int* column = new int[n];
        for (int i = 0; i < n; i++) {
            column[i] = matrix[i][j];
        }

        int minVal = findMin(column, n);
        int maxVal = findMax(column, n);

        replaceValue(column, n, minVal);
        replaceValue(column, n, maxVal);

        for (int i = 0; i < n; i++) {
            matrix[i][j] = column[i];
        }

        delete[] column;
    }

    cout << "\nМатрица после обработки:" << endl;
    printMatrix(matrix, n, m);

    ofstream output("output.txt");
    output << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            output << matrix[i][j] << " ";
        }
        output << endl;
    }
    output.close();

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
