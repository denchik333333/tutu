#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Toy {
    string name;
    double price;
    int minAge;
    int maxAge;
};

Toy inputToy() {
    Toy toy;
    cout << "Введите название игрушки: ";
    getline(cin >> ws, toy.name);

    cout << "Введите стоимость игрушки: ";
    while (!(cin >> toy.price) || toy.price <= 0) {
        cout << "Некорректный ввод. Введите положительное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите минимальный возраст: ";
    while (!(cin >> toy.minAge) || toy.minAge < 0) {
        cout << "Некорректный ввод. Введите неотрицательное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите максимальный возраст: ";
    while (!(cin >> toy.maxAge) || toy.maxAge < toy.minAge) {
        cout << "Некорректный ввод. Введите число больше минимального возраста: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return toy;
}

void printToy(const Toy& toy) {
    cout << "Название: " << toy.name << endl;
    cout << "Стоимость: " << fixed << setprecision(2) << toy.price << " руб." << endl;
    cout << "Возраст: от " << toy.minAge << " до " << toy.maxAge << " лет" << endl;
}

void printToys(const vector<Toy>& toys) {
    for (const auto& toy : toys) {
        printToy(toy);
        cout << "---------------------" << endl;
    }
}

vector<Toy> findByName(const vector<Toy>& toys, const string& name) {
    vector<Toy> result;
    for (const auto& toy : toys) {
        if (toy.name.find(name) != string::npos) {
            result.push_back(toy);
        }
    }
    return result;
}

vector<Toy> findMostExpensive(const vector<Toy>& toys) {
    if (toys.empty()) return {};

    double maxPrice = max_element(toys.begin(), toys.end(),
        [](const Toy& a, const Toy& b) { return a.price < b.price; })->price;

    vector<Toy> result;
    for (const auto& toy : toys) {
        if (toy.price >= maxPrice - 10.0) {
            result.push_back(toy);
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Toy> toys;
    int choice;

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить игрушку" << endl;
        cout << "2. Показать все игрушки" << endl;
        cout << "3. Поиск по названию" << endl;
        cout << "4. Найти самые дорогие игрушки" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Toy newToy = inputToy();
            toys.push_back(newToy);
            cout << "Игрушка добавлена!" << endl;
            break;
        }
        case 2: {
            if (toys.empty()) {
                cout << "Список игрушек пуст." << endl;
            }
            else {
                printToys(toys);
            }
            break;
        }
        case 3: {
            if (toys.empty()) {
                cout << "Список игрушек пуст." << endl;
                break;
            }
            string name;
            cout << "Введите название для поиска: ";
            getline(cin >> ws, name);
            vector<Toy> found = findByName(toys, name);
            if (found.empty()) {
                cout << "Игрушки с таким названием не найдены." << endl;
            }
            else {
                printToys(found);
            }
            break;
        }
        case 4: {
            vector<Toy> expensive = findMostExpensive(toys);
            if (expensive.empty()) {
                cout << "Список игрушек пуст." << endl;
            }
            else {
                cout << "Самые дорогие игрушки:" << endl;
                printToys(expensive);
            }
            break;
        }
        case 0: {
            cout << "Выход из программы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
        }
    } while (choice != 0);

    return 0;
}