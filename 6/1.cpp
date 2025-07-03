#include <iostream>
#include <climits>
#include <string>
using namespace std;

int findMaxOdd(const int arr[], int size) {
    int maxOdd = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0 && arr[i] > maxOdd) {
            maxOdd = arr[i];
        }
    }

    return maxOdd;
}

int findMinEven(const int arr[], int size) {
    int minEven = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && arr[i] < minEven) {
            minEven = arr[i];
        }
    }

    return minEven;
}

void findBoth(const int arr[], int size, int& maxOdd, int& minEven) {
    maxOdd = INT_MIN;
    minEven = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0 && arr[i] > maxOdd) {
            maxOdd = arr[i];
        }
        if (arr[i] % 2 == 0 && arr[i] < minEven) {
            minEven = arr[i];
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 10;
    int arr[SIZE] = { 3, 8, 12, 5, 7, 2, 9, 4, 11, 6 };

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int maxOdd = findMaxOdd(arr, SIZE);
    int minEven = findMinEven(arr, SIZE);

    cout << "Наибольшее нечетное число: "
        << (maxOdd != INT_MIN ? to_string(maxOdd) : "не найдено") << endl;
    cout << "Наименьшее четное число: "
        << (minEven != INT_MAX ? to_string(minEven) : "не найдено") << endl;

    int combinedMaxOdd, combinedMinEven;
    findBoth(arr, SIZE, combinedMaxOdd, combinedMinEven);

    cout << "\nРезультат комбинированной функции:" << endl;
    cout << "Наибольшее нечетное: "
        << (combinedMaxOdd != INT_MIN ? to_string(combinedMaxOdd) : "не найдено") << endl;
    cout << "Наименьшее четное: "
        << (combinedMinEven != INT_MAX ? to_string(combinedMinEven) : "не найдено") << endl;

    return 0;
}