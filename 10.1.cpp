#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string surname;
    string name;
    int classNumber;
    char classLetter;
};

int main() {
    const int n = 10;
    vector<Student> students(n);

    cout << "Введите данные 10 учеников (фамилия имя номер_класса буква_класса):\n";
    for (int i = 0; i < n; i++) {
        cin >> students[i].surname >> students[i].name >> students[i].classNumber >> students[i].classLetter;
    }

    bool found = false;
    cout << "Однофамильцы, обучающиеся в одном классе:\n";

    // Проверяем каждую пару учеников
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].surname == students[j].surname &&
                students[i].classNumber == students[j].classNumber &&
                students[i].classLetter == students[j].classLetter) {
                cout << students[i].surname << " из класса "
                     << students[i].classNumber << students[i].classLetter
                     << ": " << students[i].name << " и " << students[j].name << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Таких учеников нет." << endl;
    }

    return 0;
}