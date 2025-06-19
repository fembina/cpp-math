#include <iostream>
#include <cmath>

using namespace std;

// Функция f(x), переписанная из уравнения x = f(x)
double f(double x) {
    // Из уравнения 2x^3 + 4x - 1 = 0
    // Выразим x: x = (1 - 2x^3) / 4
    return (1 - 2 * pow(x, 3)) / 4.0;
}

int main() {
    double x_prev = 0.11; // начальное приближение
    double x_next;
    double epsilon;

    cout << "Введите точность E: ";
    cin >> epsilon;

    int iteration = 0;

    do {
        x_next = f(x_prev);
        iteration++;
    } while (fabs(x_next - x_prev) > epsilon && iteration < 10000); // ограничение итераций

    cout << "Корень уравнения: " << x_next << endl;
    cout << "Число итераций: " << iteration << endl;

    return 0;
}