#include <iostream>

using namespace std;

int main() {
    char digit;

    cout << "Введите цифру (0-9): ";
    cin >> digit;

    if (digit < '0' || digit > '9') {
        cout << "Ошибка: введён не символ цифры." << endl;
        return 1;
    }

    // Вычисляем предыдущую цифру
    char prev = (digit == '0') ? '9' : digit - 1;

    // Вычисляем следующую цифру
    char next = (digit == '9') ? '0' : digit + 1;

    cout << "Предыдущая цифра: " << prev << endl;
    cout << "Следующая цифра: " << next << endl;

    return 0;
}