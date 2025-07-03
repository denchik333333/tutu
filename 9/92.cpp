#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string processString(const string& input) {
    string result;
    bool inDigitSequence = false;

    for (char c : input) {
        if (isdigit(c)) {
            if (!inDigitSequence) {
                result += '#';
                inDigitSequence = true;
            }
        }
        else {
            result += c;
            inDigitSequence = false;
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("F1.txt");
    ofstream outputFile("F2.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла F1.txt" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка создания файла F2.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        string processed = processString(line);
        outputFile << processed << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Текст успешно обработан и записан в F2.txt" << endl;

    return 0;
}