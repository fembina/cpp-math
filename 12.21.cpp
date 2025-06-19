#include <iostream>
#include <string>

using namespace std;

class Binary1 {
public:
    string intPart; // целая часть в двоичной системе, строка из '0' и '1'
    string fracPart; // дробная часть в двоичной системе, строка из '0' и '1'

    void vvod();
    void vyvod() const;

private:
    bool isValidBinary(const string& s) const;
};

bool Binary1::isValidBinary(const string& s) const {
    for (char c : s) {
        if (c != '0' && c != '1')
            return false;
    }
    return true;
}

void Binary1::vvod() {
    cout << "Введите целую часть двоичного числа: ";
    cin >> intPart;

    while (!isValidBinary(intPart)) {
        cout << "Ошибка! Введите корректную целую часть (только 0 и 1): ";
        cin >> intPart;
    }

    cout << "Введите дробную часть двоичного числа (если нет - введите 0): ";
    cin >> fracPart;

    while (!isValidBinary(fracPart)) {
        cout << "Ошибка! Введите корректную дробную часть (только 0 и 1): ";
        cin >> fracPart;
    }
}

void Binary1::vyvod() const {
    cout << "Двоичное число: " << intPart;

    if (!fracPart.empty() && fracPart != "0") {
        cout << "." << fracPart;
    }

    cout << endl;
}

int main() {
    Binary1 num;

    num.vvod();
    num.vyvod();

    return 0;
}