#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateY(double x, double a) {
    if (x < -1) {
        return x + a;
    }
    else if (x >= -1 && x <= 1) {
        return a;
    }
    else {
        return -x + a;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << fixed << setprecision(2);

    for (int a = 1; a <= 5; a++) {
        cout << "Таблица значений Y(x) для a = " << a << endl;
        cout << "-------------------------------" << endl;
        cout << "   x   |   Y(x)" << endl;
        cout << "-------------------------------" << endl;

        for (double x = -4.0; x <= 4.0; x += 0.5) {
            double y = calculateY(x, a);

            cout << setw(6) << x << " |" << setw(7) << y << endl;
        }

        cout << endl << endl;
    }

    return 0;
}