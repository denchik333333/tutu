#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

double Square(double r1, double r2) {
    if (r1 < r2) {
        return 0.0;
    }
    return PI * (pow(r1, 2) - pow(r2, 2));
}

int main() {
    setlocale(LC_ALL, "Russian");
    double radius1, radius2;

    cout << "Вычисление площади кольца" << endl;
    cout << "-------------------------" << endl;
    cout << "Введите внешний радиус кольца (r1): ";
    cin >> radius1;
    cout << "Введите внутренний радиус кольца (r2): ";
    cin >> radius2;

    double area = Square(radius1, radius2);
    cout << "-------------------------" << endl;

    if (area == 0.0) {
        cout << "Ошибка: внешний радиус меньше внутреннего!" << endl;
    }
    else {
        cout << "Площадь кольца: " << area << endl;
    }

    return 0;
}