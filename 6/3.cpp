#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomArray(int* arr, int size, int minVal, int maxVal) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

bool isSortedAscending(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void insertToSorted(int*& arr, int& size, int value) {

    int* temp = new int[size + 1];

    int pos = 0;
    while (pos < size && arr[pos] < value) {
        pos++;
    }

    for (int i = 0; i < pos; i++) {
        temp[i] = arr[i];
    }

    temp[pos] = value;

    for (int i = pos; i < size; i++) {
        temp[i + 1] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size++;
}

void mergeArrays(int*& A, int& sizeA, int* B, int sizeB) {
    for (int i = 0; i < sizeB; i++) {
        insertToSorted(A, sizeA, B[i]);
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int sizeA, sizeB;
    int minVal, maxVal;

    cout << "Введите размер упорядоченного массива A: ";
    cin >> sizeA;
    cout << "Введите размер случайного массива B: ";
    cin >> sizeB;
    cout << "Введите диапазон значений для массива B (min max): ";
    cin >> minVal >> maxVal;

    int* A = new int[sizeA];
    cout << "Введите " << sizeA << " упорядоченных элементов массива A:\n";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    if (!isSortedAscending(A, sizeA)) {
        cout << "Ошибка: массив A должен быть упорядочен по возрастанию!\n";
        delete[] A;
        return 1;
    }

    int* B = new int[sizeB];
    generateRandomArray(B, sizeB, minVal, maxVal);

    cout << "\nМассив A (до слияния): ";
    printArray(A, sizeA);
    cout << "Массив B: ";
    printArray(B, sizeB);

    mergeArrays(A, sizeA, B, sizeB);

    cout << "\nМассив A (после слияния): ";
    printArray(A, sizeA);

    delete[] A;
    delete[] B;

    return 0;
}