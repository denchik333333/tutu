#include <iostream>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        int K;
        double n;

        cout << "Введите количество блоков K: ";
        cin >> K;

        cout << "Введите размер блока n (блок имеет размер n x n x 2n): ";
        cin >> n;

        double containerVolume = 8 * 8 * 12;
        double blockVolume = n * n * 2 * n;

        double totalBlocksVolume = blockVolume * K;

        if (blockVolume > containerVolume) {
            cout << "Один блок слишком велик и не помещается в контейнер.\n";
        }
        else if (totalBlocksVolume <= containerVolume) {
            cout << "Все блоки помещаются в контейнер.\n";
        }
        else {
            int maxBlocksFit = containerVolume / blockVolume;
            int remaining = K - maxBlocksFit;
            cout << "В контейнер помещается только " << maxBlocksFit << " блок(ов).\n";
            cout << "Осталось за пределами контейнера: " << remaining << " блок(ов).\n";
        }

        cout << "\nПовторить? (1 — Да, 2 — Нет): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nПерезапуск...\n\n";
                break;
            case 2:
                cout << "Завершение программы.\n";
                break;
            default:
                cout << "Неверный выбор. Завершение.\n";
                choice = 2;
        }

    } while (choice == 1);

    return 0;
}
