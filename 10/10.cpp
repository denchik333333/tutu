#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Korotishka {
    string name;
    int umniy;
    int smeliy;
    int dobriy;
};

vector<Korotishka> readDataFromFile(const string& filename) {
    ifstream file(filename);
    vector<Korotishka> korotishki;

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return korotishki;
    }

    string header;
    for (int i = 0; i < 4; i++) {
        getline(file, header);
    }

    Korotishka k;
    while (file >> k.name >> k.umniy >> k.smeliy >> k.dobriy) { 
        korotishki.push_back(k);
    }

    file.close();
    return korotishki;
}

string findMaxScorer(const vector<Korotishka>& korotishki, const string& category) {
    if (korotishki.empty()) return "Нет данных";

    auto maxIt = korotishki.begin();
    int maxVal = 0;

    if (category == "umniy") {
        maxIt = max_element(korotishki.begin(), korotishki.end(),
            [](const Korotishka& a, const Korotishka& b) { return a.umniy < b.umniy; });
        maxVal = maxIt->umniy;
    }
    else if (category == "smeliy") {
        maxIt = max_element(korotishki.begin(), korotishki.end(),
            [](const Korotishka& a, const Korotishka& b) { return a.smeliy < b.smeliy; });
        maxVal = maxIt->smeliy;
    }
    else if (category == "dobriy") {
        maxIt = max_element(korotishki.begin(), korotishki.end(),
            [](const Korotishka& a, const Korotishka& b) { return a.dobriy < b.dobriy; });
        maxVal = maxIt->dobriy;
    }

    return maxIt->name + " (" + to_string(maxVal) + " баллов)";
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Korotishka> korotishki = readDataFromFile("test_results.txt");

    if (korotishki.empty()) {
        cout << "Не удалось прочитать данные. Проверьте файл test_results.txt" << endl;
        return 1;
    }

    string smartest = findMaxScorer(korotishki, "umniy");
    string bravest = findMaxScorer(korotishki, "smeliy");
    string kindest = findMaxScorer(korotishki, "dobriy");

    cout << "Результаты тестирования:" << endl;
    cout << "-----------------------" << endl;
    cout << "Самый умный: " << smartest << endl;
    cout << "Самый смелый: " << bravest << endl;
    cout << "Самый добрый: " << kindest << endl;

    return 0;
}