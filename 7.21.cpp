#include <iostream>

using namespace std;

// Функция для нахождения НОД (наибольшего общего делителя) — алгоритм Евклида
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// Функция для сокращения дроби
void reduceFraction(int &num, int &den) {
    int divisor = gcd(abs(num), abs(den));

    // делим и тут же присваиваем
    num /= divisor;
    den /= divisor;

    // Если знаменатель отрицательный, меняем знак у числителя и знаменателя
    if (den < 0) {
        den = -den;
        num = -num;
    }
}

int main() {
    int a, b, c, d;

    cout << "Введите первую дробь (a b): ";
    cin >> a >> b;

    cout << "Введите вторую дробь (c d): ";
    cin >> c >> d;

    // Проверка знаменателей не равны нулю
    if (b == 0 || d == 0) {
        cout << "Знаменатель не может быть равен нулю!" << endl;

        return 1;
    }

    // Сложение дробей: a/b + c/d = (a*d + c*b) / (b*d)
    int numerator = a * d + c * b;
    int denominator = b * d;

    // Сокращаем дробь
    reduceFraction(numerator, denominator);

    cout << "Сумма дробей: " << numerator << "/" << denominator << endl;

    return 0;
}