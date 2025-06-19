#include <iostream>
#include <string>

using namespace std;

struct Student {
    string surname;
    string name;
    int classNumber;
    int grades[3]; // оценки по трем предметам
};

int main() {
    const int n = 10;
    Student students[n];

    cout << "Введите данные 10 учеников (фамилия имя номер_класса 3_оценки):\n";
    for (int i = 0; i < n; i++) {
        cin >> students[i].surname >> students[i].name >> students[i].classNumber;
        for (int j = 0; j < 3; j++) {
            cin >> students[i].grades[j];
        }
    }

    int targetClass;
    cout << "Введите номер класса для поиска отличников: ";
    cin >> targetClass;

    bool found = false;
    cout << "Отличники класса " << targetClass << ":\n";

    for (int i = 0; i < n; i++) {
        if (students[i].classNumber == targetClass) {
            bool isExcellent = true;
            for (int j = 0; j < 3; j++) {
                if (students[i].grades[j] != 5) {
                    isExcellent = false;
                    break;
                }
            }
            if (isExcellent) {
                cout << students[i].surname << " " << students[i].name << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Отличников в классе " << targetClass << " нет." << endl;
    }

    return 0;
}