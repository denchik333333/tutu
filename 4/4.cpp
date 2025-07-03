#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int initial_cells = 1; 
    const int hours = 48;        
    const int division_period = 3; 

    int current_cells = initial_cells;

    cout << "Таблица роста бактериальной колонии:" << endl;
    cout << "------------------------------------" << endl;
    cout << " Время (часы) | Количество клеток " << endl;
    cout << "------------------------------------" << endl;

    for (int hour = 0; hour <= hours; hour++) {
        if (hour % division_period == 0 || hour == hours) {
            cout << setw(10) << hour << "   |" << setw(18) << current_cells << endl;
        }

        if (hour > 0 && hour % division_period == 0) {
            current_cells *= 2;
        }
    }
    cout << "------------------------------------" << endl;
    cout << "Итоговое количество клеток через " << hours << " часов: " << current_cells << endl;
    return 0;
}