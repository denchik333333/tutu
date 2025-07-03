#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string formatNumber(long long n) {
    string numStr = to_string(n);
    string result;
    int count = 0;

    for (int i = numStr.length() - 1; i >= 0; i--) {
        result += numStr[i];
        count++;

        if (count % 3 == 0 && i != 0) {
            result += ' ';
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    long long number;

    cout << "Введите натуральное число: ";
    cin >> number;

    if (number < 0) {
        cout << "Ошибка: число должно быть натуральным!" << endl;
        return 1;
    }

    string formatted = formatNumber(number);
    cout << "Форматированное число: " << formatted << endl;

    return 0;
}