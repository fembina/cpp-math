#include <iostream>

using namespace std;

// функция нахождения максимального числа из двух
int max(int k, int m) {
    return (k > m) ? k : m; // это сокращенное условие if/else, так можно в одну строку писать красиво :3
}

int main() {
    int a, b, c, d;

    cout << "Введите четыре числа (a, b, c, d): ";

    cin >> a >> b >> c >> d;

    int x = max(a, b);
    int y = max(c, d);
    int z = max(x, y);

    cout << "x = max(a, b) = " << x << endl;
    cout << "y = max(c, d) = " << y << endl;
    cout << "z = max(x, y) = " << z << endl;

    return 0;
}