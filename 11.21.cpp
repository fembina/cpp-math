#include <iostream>
#include <cmath>

using namespace std;

class OctalNumber {
public:
    int first; // целая часть (восьмеричная)
    int second; // дробная часть (восьмеричная, положительное целое число)

    void Read();
    void Display();
    OctalNumber add8(const OctalNumber& other);

private:
    // Вспомогательные функции
    int octalToDecimalInt(int oct);
    int decimalToOctalInt(int dec);
    double octalFractionToDecimal(int octFrac);
    int decimalFractionToOctal(double decFrac, int precision = 5);
};

void OctalNumber::Read() {
    cout << "Введите целую часть (восьмеричная): ";
    cin >> first;

    cout << "Введите дробную часть (восьмеричная, положительное целое): ";
    cin >> second;
}

void OctalNumber::Display() {
    cout << "Результат (восьмеричная система): ";
    cout << first << "." << second << endl;
}

// Преобразование целой части из восьмеричной в десятичную
int OctalNumber::octalToDecimalInt(int oct) {
    int dec = 0, base = 1;

    while (oct > 0) {
        int digit = oct % 10;

        if (digit >= 8) {
            cout << "Ошибка: некорректная восьмеричная цифра!" << endl;
            exit(1);
        }

        dec += digit * base;
        base *= 8;
        oct /= 10;
    }

    return dec;
}

// Преобразование десятичного целого в восьмеричное
int OctalNumber::decimalToOctalInt(int dec) {
    int oct = 0, base = 1;

    while (dec > 0) {
        int rem = dec % 8;
        oct += rem * base;
        base *= 10;
        dec /= 8;
    }

    return oct;
}

// Преобразование дробной части из восьмеричной в десятичную
double OctalNumber::octalFractionToDecimal(int octFrac) {
    double decFrac = 0.0;
    double base = 1.0 / 8.0;

    while (octFrac > 0) {
        int digit = octFrac % 10;

        if (digit >= 8) {
            cout << "Ошибка: некорректная восьмеричная цифра во дробной части!" << endl;
            exit(1);
        }

        decFrac += digit * base;
        base /= 8.0;
        octFrac /= 10;
    }
    return decFrac;
}

// Преобразование десятичной дроби в восьмеричное целое с точностью precision цифр
int OctalNumber::decimalFractionToOctal(double decFrac, int precision) {
    int octFrac = 0;
    
    for (int i = 0; i < precision; i++) {
        decFrac *= 8;
        int digit = static_cast<int>(decFrac);
        if (digit >= 8) digit = 7; // на всякий случай
        octFrac = octFrac * 10 + digit;
        decFrac -= digit;
    }
    
    return octFrac;
}

OctalNumber OctalNumber::add8(const OctalNumber& other) {
    // Преобразуем целые части в десятичные
    int decFirst = octalToDecimalInt(this->first);
    int decSecond = octalToDecimalInt(other.first);

    // Преобразуем дробные части в десятичные
    double fracFirst = octalFractionToDecimal(this->second);
    double fracSecond = octalFractionToDecimal(other.second);

    // Складываем
    double sum = (decFirst + decSecond) + (fracFirst + fracSecond);

    // Отделяем целую и дробную часть
    int sumInt = static_cast<int>(sum);
    double sumFrac = sum - sumInt;

    // Преобразуем обратно в восьмеричную систему
    OctalNumber result;
    result.first = decimalToOctalInt(sumInt);
    result.second = decimalFractionToOctal(sumFrac);

    return result;
}

int main() {
    OctalNumber num1, num2, sum;

    cout << "Введите первое восьмеричное число:\n";
    num1.Read();

    cout << "Введите второе восьмеричное число:\n";
    num2.Read();

    sum = num1.add8(num2);

    cout << "Сумма: ";
    sum.Display();

    return 0;
}