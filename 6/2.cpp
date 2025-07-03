#include <iostream>
using namespace std;

void inputArray(int arr[], int size) {
    cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
void printArray(const int arr[], int size) {
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSortedAscending(const int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void insertToSorted(int arr[], int& size, int value) {
    int pos = 0;
    while (pos < size && arr[pos] < value) {
        pos++;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    size++;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    inputArray(arr, size);
    printArray(arr, size);

    if (isSortedAscending(arr, size)) {
        cout << "Массив упорядочен по возрастанию\n";

        int value;
        cout << "Введите значение для вставки: ";
        cin >> value;

        insertToSorted(arr, size, value);
        cout << "После вставки:\n";
        printArray(arr, size);
    }
    else {
        cout << "Массив не упорядочен по возрастанию\n";
    }

    return 0;
}