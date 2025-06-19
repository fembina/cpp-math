#include <iostream>

using namespace std;

class ArithmeticProgression {
public:
    float first; // a0 - первый элемент прогрессии
    int second; // d - разность прогрессии

    void Read(); // ввод с клавиатуры
    void Display(); // вывод результата
    float element_i(int i); // вычисление i-го элемента прогрессии

private:
    float result; // хранит результат вычисления
};

void ArithmeticProgression::Read() {
    cout << "Введите первый элемент прогрессии (a0): ";
    cin >> first;
    cout << "Введите разность прогрессии (d): ";
    cin >> second;
}

float ArithmeticProgression::element_i(int i) {
    result = first + i * second;
    return result;
}

void ArithmeticProgression::Display() {
    cout << "Результат: " << result << endl;
}

int main() {
    ArithmeticProgression prog;
    prog.Read();

    int i;
    cout << "Введите индекс элемента i для вычисления: ";
    cin >> i;

    prog.element_i(i);
    prog.Display();

    return 0;
}