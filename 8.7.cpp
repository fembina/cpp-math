#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления биномиальных коэффициентов С(m,n) по заданным формулам
int binomialCoeff(int m, int n) {
    // Базовые случаи
    if (m == 0 && n >= 0) return 1;
    if (m > n && n >= 0) return 0;
    if (n >= m && m > 0) return binomialCoeff(m - 1, n - 1) + binomialCoeff(m, n - 1);

    // По условию остальные случаи не определены, можно вернуть 0
    return 0;
}

int main() {
    int m, n;
    
    cout << "Введите m и n (через пробел): ";
    cin >> m >> n;

    if (n < 0 || m < 0) {
        cout << "m и n должны быть неотрицательными числами." << endl;
        return 1;
    }

    int result = binomialCoeff(m, n);
    cout << "C(" << m << ", " << n << ") = " << result << endl;

    return 0;
}