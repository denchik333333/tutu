#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double minSalary, gradeCoeff, bonusPercent;
    const double uralCoeff = 0.15;
    const double taxRate = 0.12;

    cout << "Введите минимальную зарплату: ";
    cin >> minSalary;

    cout << "Введите разрядный коэффициент (1.0 - 3.0): ";
    cin >> gradeCoeff;

    cout << "Введите премию (в %): ";
    cin >> bonusPercent;

    double baseSalary = minSalary * gradeCoeff;

    double salaryWithUral = baseSalary * (1 + uralCoeff);

    double salaryWithBonus = salaryWithUral * (1 + bonusPercent / 100.0);

    double finalSalary = salaryWithBonus * (1 - taxRate);

    cout << "Итоговая зарплата сотрудника: " << finalSalary << " руб." << endl;

    return 0;
}
