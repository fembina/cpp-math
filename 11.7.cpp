#include <iostream>
using namespace std;

class RangeChecker {
public:
    double first; // левая граница диапазона
    double second;// правая граница диапазона

    void Read(); // ввод границ диапазона
    void Display(); // вывод результата проверки
    bool rangecheck(double x); // проверка принадлежности числа диапазону

private:
    bool result;
};

void RangeChecker::Read() {
    cout << "Введите левую границу диапазона: ";
    cin >> first;

    cout << "Введите правую границу диапазона: ";
    cin >> second;
}

bool RangeChecker::rangecheck(double x) {
    // Проверяем принадлежит ли x диапазону [first, second]
    // При этом предполагается, что first <= second, если нет — поменяем местами
    double left = first < second ? first : second;
    double right = first > second ? first : second;

    result = (x >= left && x <= right);
    return result;
}

void RangeChecker::Display() {
    if (result) {
        cout << "Число принадлежит диапазону." << endl;
    } else {
        cout << "Число НЕ принадлежит диапазону." << endl;
    }
}

int main() {
    RangeChecker rc;
    rc.Read();

    double x;
    cout << "Введите число для проверки: ";
    cin >> x;

    rc.rangecheck(x);
    rc.Display();

    return 0;
}