#include <iostream>
#include <cmath>

using namespace std;

class EngMer {
public:
    int pounds; // фунты
    float inches; // дюймы

    void vvod();
    void vyvod() const;

    // Арифметические операции
    EngMer add(const EngMer& other) const;
    EngMer sub(const EngMer& other) const;
    EngMer mul(float scalar) const;
    EngMer div(float scalar) const;
    bool equ(const EngMer& other) const;

private:
    // Вспомогательные функции для нормализации
    void normalize();
};

void EngMer::vvod() {
    cout << "Введите фунты: ";
    cin >> pounds;
    cout << "Введите дюймы: ";
    cin >> inches;
    normalize();
}

void EngMer::vyvod() const {
    cout << pounds << " фунт(ов) " << inches << " дюйм(ов)";
}

// Переводим лишние дюймы в фунты (1 фунт = 12 дюймов)
void EngMer::normalize() {
    if (inches >= 12.0f) {
        pounds += (int)(inches / 12);
        inches = fmod(inches, 12.0f);
    }
    else if (inches < 0) {
        int borrow = (int)((-inches) / 12) + 1;
        pounds -= borrow;
        inches += borrow * 12;
    }
    if (pounds < 0 && inches > 0) {
        pounds += 1;
        inches -= 12;
    }
}

EngMer EngMer::add(const EngMer& other) const {
    EngMer result;
    result.pounds = pounds + other.pounds;
    result.inches = inches + other.inches;
    result.normalize();
    return result;
}

EngMer EngMer::sub(const EngMer& other) const {
    EngMer result;
    result.pounds = pounds - other.pounds;
    result.inches = inches - other.inches;
    result.normalize();
    return result;
}

EngMer EngMer::mul(float scalar) const {
    // Переводим всё в дюймы, умножаем, потом обратно
    float totalInches = (pounds * 12.0f + inches) * scalar;
    EngMer result;
    result.pounds = (int)(totalInches / 12);
    result.inches = fmod(totalInches, 12.0f);
    return result;
}

EngMer EngMer::div(float scalar) const {
    if (scalar == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return *this;
    }
    float totalInches = (pounds * 12.0f + inches) / scalar;
    EngMer result;
    result.pounds = (int)(totalInches / 12);
    result.inches = fmod(totalInches, 12.0f);
    return result;
}

bool EngMer::equ(const EngMer& other) const {
    return (pounds == other.pounds) && (fabs(inches - other.inches) < 1e-5);
}

int main() {
    EngMer e1, e2;

    cout << "Введите первую длину:\n";
    e1.vvod();
    cout << "Введите вторую длину:\n";
    e2.vvod();

    cout << "\nПервая длина: ";
    e1.vyvod();
    cout << "\nВторая длина: ";
    e2.vyvod();

    EngMer sum = e1.add(e2);
    cout << "\nСумма: ";
    sum.vyvod();

    EngMer diff = e1.sub(e2);
    cout << "\nРазность: ";
    diff.vyvod();

    float scalar;
    cout << "\nВведите число для умножения: ";
    cin >> scalar;
    EngMer prod = e1.mul(scalar);
    cout << "Умножение первой длины на " << scalar << ": ";
    prod.vyvod();

    cout << "\nВведите число для деления: ";
    cin >> scalar;
    EngMer quot = e1.div(scalar);
    cout << "Деление первой длины на " << scalar << ": ";
    quot.vyvod();

    cout << "\nСравнение первой и второй длины: ";
    if (e1.equ(e2)) cout << "Длины равны\n";
    else cout << "Длины не равны\n";

    return 0;
}